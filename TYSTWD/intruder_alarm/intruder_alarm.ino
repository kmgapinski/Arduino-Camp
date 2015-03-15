/*Intruder Alarm
TYSTWD
*/


#include <Servo.h>  // servo library
Servo servo1;  // servo control object
//Pins
const int trip_wire = 12; //input
const int ir_rec = 11; //input
const int buzzerPin = 9; //out
const int ledPin = 8; //out
const int servoPin = 5; //out
const int shockPin = 6;//out



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
  servo1.write(0);
  delay(200);

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
  servo1.write(12);
  delay(200);
}

void shock(){
  for(int index = 0; index <= 7; index++)
  {
    digitalWrite(shockPin, HIGH);
    delay(100);
    digitalWrite(shockPin, LOW); 
    delay(100);   
  }
}

void cleanup(){
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
  digitalWrite(shockPin, LOW);
  servo1.write(0);
  delay(200);
}
