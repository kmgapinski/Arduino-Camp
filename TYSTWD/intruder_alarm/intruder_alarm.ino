/*Intruder Alarm
TYSTWD
*/


#include <Servo.h>  // servo library
Servo servo1;  // servo control object
//Pins
const int trip_wire = 12; //input
const int ir_rec = 11; //input
const int buzzerPin = 10; //out
const int ledPin = 9; //out
const int servoPin = 8; //out
const int shockPin = 7;//out



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(servoPin);
  pinMode(13, OUTPUT);
  pinMode(trip_wire, INPUT);
  pinMode(ir_rec, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(shockPin, OUTPUT);

}

void loop() {
    
  if ( tripWire() || proxySensor() ){
    light();
    call4help();
    buzzer();
    picture();
    shock();
    
  }
  delay(2000);
  cleanup();
}





int tripWire(){
  return digitalRead(trip_wire);
}

int proxySensor(){
  if(digitalRead(ir_rec)== HIGH){
    digitalWrite(13, HIGH);
    return 1;
  } else{
    digitalWrite(13, LOW);
    return 0;
  };
}

void buzzer(){
  tone(buzzerPin, 1000);
}

void light(){
  digitalWrite(ledPin, HIGH);
}

void call4help(){
  Serial.println("Intruder Detected - Alerting Authorities");
  delay(100);
}

void picture(){
}

void shock(){
  
}

void cleanup(){
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
}
