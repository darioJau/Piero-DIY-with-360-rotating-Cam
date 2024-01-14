#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>

String ssid = "Iphone de David";
String password = "12345678";
String mqtt_server = "iot.ac.uma.es"; 
String mqtt_user = "II10";
String mqtt_pass = "wD9IYehI";
String ID_PLACA = String(ESP.getEfuseMac());
String topicPiero = "II10/ESP"+ID_PLACA+"/mando/piero";
String topicCamara = "II10/ESP"+ID_PLACA+"/mando/camara";
String topic_PUB_conexion = "II10/ESP"+ID_PLACA+"/mando/conexion";
String mensaje_conexion = "{\"mando\":connected}";
String LWT = "{\"mando\":disconnected}";

WiFiClient wClient;
PubSubClient mqtt_client(wClient);
// Pines para los indicadores de conexión
const int pinRojo = 5;
const int pinVerde = 18;
// Pines para los joysticks
const int pinxCamara = 33;
const int pinyCamara = 32;
const int pinButtonCamara = 17;

const int pinxPiero = 34;
const int pinyPiero = 39;
const int pinButtonPiero = 16;

const int rango = 6;

// Tamaño del buffer para mensajes JSON
const size_t bufferSize = 512;

// Variables para almacenar las lecturas
int oldxValueCamara = 0, newxValueCamara = 0;
int oldyValueCamara = 0, newyValueCamara = 0;
int oldButtonCamara = 1, newButtonCamara = 1;

int oldxValuePiero = 0, newxValuePiero = 0;
int oldyValuePiero = 0, newyValuePiero = 0;
int oldButtonPiero = 1, newButtonPiero = 1;

//-----------------------------------------------------
size_t leerJoyStick(int pinx, int piny, int pinButton, int &oldx, int &newx, int &oldy, int &newy, int &oldButton, int &newButton) {
  newx = analogRead(pinx);
  newy = analogRead(piny);
  newButton = !digitalRead(pinButton);

  if (newx >= 0) {
    newx = (round((4095 - newx) * rango / 4095) - rango/2);
  } else {
    newx = (round((-4095 + newx) * rango / 4095) - rango/2);
  }

  if (newy >= 0) {
    newy = (round((4095 - newy) * rango / 4095) - rango/2);
  } else {
    newy = (round((-4095 + newy) * rango / 4095) - rango/2);
  }

  if ((newx != oldx) || (newy != oldy) || (newButton != oldButton)) {
    // Actualizamos el valor de las variables antiguas
    oldx = newx;
    oldy = newy;
    oldButton = newButton;
    return true;
  } else {
    return false;
  }
}

//-----------------------------------------------------
void conecta_wifi() {
  Serial.println("Connecting to " + String(ssid));
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println();
}
//-----------------------------------------------------
void conecta_mqtt() {// Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print("Attempting MQTT connection...");// Attempt to connect
    if (mqtt_client.connect(ID_PLACA.c_str(),mqtt_user.c_str(),mqtt_pass.c_str(),topic_PUB_conexion.c_str(),2,false,LWT.c_str())){
      Serial.println(" conectado a broker: " + String(mqtt_server.c_str()));
    } else {
      Serial.println("ERROR:"+ String(mqtt_client.state()) +" reintento en 5s" );
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
//-----------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.println("TOPIC: " + topicPiero);
  pinMode(pinButtonCamara, INPUT_PULLUP);
  pinMode(pinButtonPiero, INPUT_PULLUP);
  pinMode(pinVerde,OUTPUT);
  pinMode(pinRojo,OUTPUT);
  digitalWrite(pinVerde,LOW);
  digitalWrite(pinRojo,HIGH);
  conecta_wifi();
  mqtt_client.setServer(mqtt_server.c_str(), 1883);
  mqtt_client.setBufferSize(512); 
  conecta_mqtt();
  Serial.println("Identificador placa: "+ String(ID_PLACA));
  Serial.println("Topic publicacion control Piero: "+ String(topicPiero));
  Serial.println("Topic publicacion control Camara: "+ String(topicCamara));
  StaticJsonDocument<bufferSize> mensajePiero;
  String mensajePieroString;
  mensajePiero["X"] = 0;
  mensajePiero["Y"] = 0;
  mensajePiero["Button"] = 0;
  serializeJson(mensajePiero, mensajePieroString);
  StaticJsonDocument<bufferSize> mensajeCamara;
  String mensajeCamaraString;
  mensajeCamara["X"] = 0;
  mensajeCamara["Y"] = 0;
  mensajeCamara["Button"] = 0;
  serializeJson(mensajeCamara, mensajeCamaraString);
  mqtt_client.publish(topicPiero.c_str(),mensajePieroString.c_str());
  mqtt_client.publish(topicCamara.c_str(),mensajeCamaraString.c_str());
  Serial.println("Termina setup en " +  String(millis()) + " ms");
}
//-----------------------------------------------------
void loop() {
  static unsigned long ultimo_mensaje=0;
  static unsigned long ahora=0;

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conexión WiFi perdida. Intentando reconectar...");
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinRojo,HIGH);
    conecta_wifi();
  }else{
    digitalWrite(pinVerde,HIGH);
    digitalWrite(pinRojo,LOW);
  }

  if (!mqtt_client.connected()) {
    conecta_mqtt();
  }
  mqtt_client.loop(); // esta llamada para que la librería recupere el control
  
  ahora = millis();

  if (ahora - ultimo_mensaje >= 100) {
    ultimo_mensaje = ahora;
    if (leerJoyStick(pinxCamara, pinyCamara, pinButtonCamara, oldxValueCamara, newxValueCamara, oldyValueCamara, newyValueCamara, oldButtonCamara, newButtonCamara)){ // mandamos mensaje si cambian los valores leidos
      // Actualizamos el valor del mensaje a mandar
      StaticJsonDocument<bufferSize> mensajeCamara;
      String mensajeCamaraString;
      mensajeCamara["X"] = oldxValueCamara;
      mensajeCamara["Y"] = oldyValueCamara;
      mensajeCamara["Button"] = oldButtonCamara;
      serializeJson(mensajeCamara, mensajeCamaraString);
      Serial.print("Comando de Cámara enviado: ");
      Serial.println(mensajeCamaraString);
      mqtt_client.publish(topicCamara.c_str(),mensajeCamaraString.c_str());
    }

    if (leerJoyStick(pinxPiero, pinyPiero, pinButtonPiero, oldxValuePiero, newxValuePiero, oldyValuePiero, newyValuePiero, oldButtonPiero, newButtonPiero)) { // mandamos mensaje si cambian los valores leidos
      //Actualizamos el valor del mensaje a mandar
      StaticJsonDocument<bufferSize> mensajePiero;
      String mensajePieroString;
      mensajePiero["X"] = oldxValuePiero;
      mensajePiero["Y"] = oldyValuePiero;
      mensajePiero["Button"] = oldButtonPiero;
      serializeJson(mensajePiero, mensajePieroString);
      Serial.print("Comando de Piero enviado: ");
      Serial.println(mensajePieroString);
      mqtt_client.publish(topicPiero.c_str(),mensajePieroString.c_str());
    }
  }
}
