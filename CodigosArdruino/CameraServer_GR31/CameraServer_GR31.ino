#define CAMERA_MODEL_WROVER_KIT 
#define LED_BUILTIN 2
#define DEBUG_STRING "["+String(__FUNCTION__)+"():"+String(__LINE__)+"] "
#include "esp_camera.h"
#include <WiFi.h>
#include <string>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <Stepper.h>
#include "camera_pins.h"

const int ledVerde = 33;
const int ledRojo = 32;
const int left = 14;
const int rigth = 12;
const int pinflash = 15;

const String ssid = "Iphone de David";
const String password = "12345678";

camera_config_t config;
void startCameraServer();
void config_init();

WiFiClient wClient;
PubSubClient mqtt_client(wClient);
const String mqtt_server = "iot.ac.uma.es";
const String mqtt_user = "II10";
const String mqtt_pass = "wD9IYehI";
const String ID_PLACA = String(ESP.getEfuseMac());
const String ID_PLACA_EMISORA = "36221669107172";
const String topicCamara = "II10/ESP" + ID_PLACA_EMISORA + "/mando/camara";
const String topic_PUB_conexion = "II10/ESP"+ID_PLACA+"/camara/conexion";
const String topic_PUB_flash = "II10/ESP"+ID_PLACA+"/camara/responseFlash";
const String topic_SUB_flash = "II10/ESP"+ID_PLACA+"/camara/requestFlash";
const String topic_PUB_foto = "II10/ESP"+ID_PLACA+"/camara/fotoRutinaria";
const String topic_SUB_tiempo = "II10/ESP"+ID_PLACA+"/camara/tiempo";
const String topic_PUB_ip = "II10/ESP"+ID_PLACA+"/camara/IP";
const String topic_SUB_ip = "II10/ESP"+ID_PLACA+"/camara/IPRequest";
const String mensaje_conexion = "{\"online\":true}";
const String mensajefoto = "{\"foto_rutinaria\":1}";
const String LWT = "{\"online\":false}";


int tiempo_foto = 60; // por defecto, se toma una foto de seguridad cada 60 minutos

//-----------------------------------------------------------
//-----------------------------------------------------------
void conecta_wifi() {
  Serial.println(DEBUG_STRING+"Conectando a " + ssid);

  WiFi.begin(ssid, password);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
    delay(200);
    Serial.print(".");
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
  }
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.println();
  Serial.println(DEBUG_STRING+"WiFi conectada, dirección IP: " + WiFi.localIP().toString());
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void conecta_mqtt() {// Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print(DEBUG_STRING+"Attempting MQTT connection...");// Attempt to connect
    if (mqtt_client.connect(ID_PLACA.c_str(),mqtt_user.c_str(),mqtt_pass.c_str(),topic_PUB_conexion.c_str(),2,false,LWT.c_str())) {
      Serial.println(" conectado a broker: " + mqtt_server);
        mqtt_client.subscribe(topic_SUB_flash.c_str());  
        mqtt_client.subscribe(topic_SUB_tiempo.c_str()); 
        mqtt_client.subscribe(topicCamara.c_str());
        mqtt_client.subscribe(topic_SUB_ip.c_str());
        mqtt_client.publish(topic_PUB_ip.c_str(), (WiFi.localIP().toString()).c_str());
    } else {
      Serial.println("ERROR:"+ String(mqtt_client.state()) +" reintento en 5s" );
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
//----------------------------------------------------------- 
//-----------------------------------------------------------
void procesa_mensaje(char* topic, byte* payload, unsigned int length) { 
  String mensaje=String(std::string((char*) payload,length).c_str());
  Serial.println("Mensaje recibido ["+ String(topic) +"] "+ mensaje);
  if(String(topic)==topic_SUB_tiempo){
    DynamicJsonDocument mensaje_json(50);
    DeserializationError error = deserializeJson(mensaje_json,mensaje);
    if(not error){
      tiempo_foto = mensaje_json["tiempo"];
      Serial.println(DEBUG_STRING + "Actualizando tiempo de foto de seguridad a "+tiempo_foto+" minutos.");
    }
  }else if(String(topic)==topic_SUB_ip){
    mqtt_client.publish(topic_PUB_ip.c_str(), (WiFi.localIP().toString()).c_str());
  }else if(String(topic)==topic_SUB_flash){
    DynamicJsonDocument mensaje_json(50);
    DeserializationError error = deserializeJson(mensaje_json,mensaje);
    if(not error){
      if(mensaje_json["flash"]==1){
        digitalWrite(pinflash, HIGH);
        Serial.println(DEBUG_STRING + "Encendiendo Flash...");
      }else{
        digitalWrite(pinflash, LOW);
        Serial.println(DEBUG_STRING + "Apagando Flash...");
      }
      mqtt_client.publish(topic_PUB_flash.c_str(), mensaje.c_str());
    }
  }else if (String(topic) == topicCamara) {
    DynamicJsonDocument mensaje_json(200);
    DeserializationError error = deserializeJson(mensaje_json, mensaje);
    if (!error) {
      if(int(mensaje_json["X"])>0){
        Serial.println("Girando a la derecha");
        digitalWrite(left, LOW);
        digitalWrite(rigth, HIGH);
      }else if(int(mensaje_json["X"])<0){
        Serial.println("Girando a la izquierda");
        digitalWrite(left, HIGH);
        digitalWrite(rigth, LOW);
      }else if (int(mensaje_json["Y"])>0){
        Serial.println("Cambiando flash");
        digitalWrite(pinflash, !digitalRead(pinflash));
        String msg;
        if(digitalRead(pinflash)){
          msg = "{\"flash\":1}";
        }else{
          msg = "{\"flash\":0}";
        }
        mqtt_client.publish(topic_PUB_flash.c_str(), msg.c_str());
      }else if (int(mensaje_json["Y"])<0){
        Serial.println("Centrando cámara");
        digitalWrite(left, HIGH);
        digitalWrite(rigth, HIGH);
      }else if (int(mensaje_json["X"])==0){
        Serial.println("Parando motor");
        digitalWrite(left, LOW);
        digitalWrite(rigth, LOW);
      }
    }
  }
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void config_init() {
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_HD;
  config.pixel_format = PIXFORMAT_JPEG; 
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 2;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  pinMode(left,OUTPUT);
  pinMode(rigth,OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(pinflash, OUTPUT);
  config_init();
  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  sensor_t * s = esp_camera_sensor_get();
  s->set_vflip(s, 0);        //1-Upside down, 0-No operation
  s->set_hmirror(s, 0);      //1-Reverse left and right, 0-No operation
  s->set_brightness(s, 1);   //up the blightness just a bit
  s->set_saturation(s, -1);  //lower the saturation

  conecta_wifi();
  startCameraServer();
  mqtt_client.setServer(mqtt_server.c_str(), 1883);
  mqtt_client.setBufferSize(512); // para poder enviar mensajes de hasta X bytes
  mqtt_client.setCallback(procesa_mensaje);
  conecta_mqtt();

  String flash_inicial = "{\"flash\": 0}";
  if (!mqtt_client.connected()) {
    conecta_mqtt();
  }else{
    mqtt_client.publish(topic_PUB_flash.c_str(),flash_inicial.c_str());
  }
}

void loop() {
  static unsigned long ultimo_mensaje=0;
  static unsigned long ahora=0;
  ahora = millis();

  if(WiFi.status() != WL_CONNECTED) {
    Serial.println(DEBUG_STRING + "Reconectando a Wifi...");
    conecta_wifi();
    digitalWrite(ledRojo,HIGH);
    digitalWrite(ledVerde,LOW);
  }else{
    digitalWrite(ledRojo,LOW);
    digitalWrite(ledVerde,HIGH);
  }

  if (!mqtt_client.connected()) {
    Serial.println(DEBUG_STRING + "Reconectando a MQTT...");
    conecta_mqtt();
  }

  mqtt_client.loop(); // esta llamada para que la librería recupere el control

  if (ahora - ultimo_mensaje >= tiempo_foto*60000) { // Mandamos foto automáticamente cada "tiempo_foto" minutos
    ultimo_mensaje = ahora;
    mqtt_client.publish(topic_PUB_foto.c_str(), mensajefoto.c_str());
  }
}


