#include <Stepper.h>

// Pines de control del motor paso a paso
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int buttonPin = 6;
const int left = 7;
const int rigth = 8;

int posicionActual = 0;
const int angle = 10;
bool origin = false; // inicializamos al modo de funcionamiento normal
const int stepsPerRevolution = 2048;  // Cambiar según la especificación del motor
const int vel = 8;

Stepper myStepper(stepsPerRevolution,IN1,IN3,IN2,IN4);

//-----------------------------------------------------
//-----------------------------------------------------
int degree2steps(const int degrees) {
  int steps = int(degrees * stepsPerRevolution / 360);
  return steps;
}
//-----------------------------------------------------
int steps2degree(const int steps) {
  int degree = int(steps * 360 / stepsPerRevolution);
  return degree;
}
//-----------------------------------------------------
void recuperarOrigen() {
  // Nos movemos al origen
  while (!origin) {
    if(digitalRead(buttonPin)) {
      Serial.println("Pulsación detectada");
      origin = true;
    } else {
      myStepper.step(-1);
    }
  }
  // Fijamos de nuevo el origen compensando el desfase para poder hacer movimientos relativos
  posicionActual = 0;
  Serial.println("Calibracion completada");
}
//-----------------------------------------------------
void controlMotor(const int comando) {
  if ((comando > 0) && (posicionActual < 360 )) { // Comprobamos que estamos dentro del rango
    Serial.println("Moving " + String(angle) + " degrees");
    myStepper.step(degree2steps(angle));
    posicionActual = posicionActual + angle;
    Serial.println("Movement completed");
  } else if ((comando < 0) && (posicionActual > 0)) {  // Comprobamos que estamos dentro del rango
    Serial.println("Moving " + String(angle) + " degrees");
    myStepper.step(degree2steps(-angle));
    posicionActual = posicionActual - angle;
    Serial.println("Movement completed");
  }
}
//-----------------------------------------------------
void setup() {
  // Inicializar la comunicación serial
  Serial.begin(115200);
  pinMode(buttonPin, INPUT); // Configuramos el pin del botón
  pinMode(left,INPUT);
  pinMode(rigth,INPUT);
  // Configura el objeto AccelStepper
  myStepper.setSpeed(vel);  
  recuperarOrigen();
  origin = false;
}

void loop() {
  if((digitalRead(left))&&(digitalRead(rigth))){
    Serial.println("Centrando cámara");
    recuperarOrigen();
  }else if((digitalRead(left))&&(!digitalRead(rigth))){
    Serial.println("Girando a la izquierda");
    controlMotor(-1);
    origin = false;
  }else if((!digitalRead(left))&&(digitalRead(rigth))){
    Serial.println("Girando a la derecha");
    controlMotor(1);
    origin = false;
  }
}
