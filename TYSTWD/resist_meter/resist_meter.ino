/*
  Analog Input

 */
int sensorPin = A0;    // select the input pin for the potentiometer
int green1Pin = 13;      // select the pin for the LED
int green2Pin = 12;
int yellow1Pin = 11;
int yellow2Pin = 10;
int redPin = 9;
int notConnectedPin = 8;
int sensorValue = 0;  // variable to store the value coming from the sensor
int wait = 100; // 100us need for alog read
//Vo = Vi*(R2/(R1+R2))
//R2 =10k Vi =5V
//Vo = 0-5 --> 0-1023
//R1 high = low V0 = red
int red = 204;
int yellow2 = 408;
int yellow1 = 612;
int green2 = 816;
//int green1 = 1020  == MAX, 1024;

void setup() {
  // declare the leds as an OUTPUT:
  Serial.begin(9600);
  pinMode(green1Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT); 
  pinMode(yellow1Pin, OUTPUT); 
  pinMode(yellow2Pin, OUTPUT); 
  pinMode(redPin, OUTPUT);
  pinMode(notConnectedPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  
  delay(wait);
  Serial.print(sensorValue);
  Serial.print("\n");

  //start  lowest
  //not connected.. 
  if (sensorValue <= 1){
    digitalWrite(notConnectedPin, HIGH); 
  } else {
     digitalWrite(notConnectedPin, LOW);
  }
  
  if (sensorValue > 1){
    digitalWrite(redPin, HIGH); 
  } else {
     digitalWrite(redPin, LOW);
  }
  
  if (sensorValue > red){
    digitalWrite(yellow2Pin, HIGH); 
  } else {
     digitalWrite(yellow2Pin, LOW);
  }
  
  if (sensorValue > yellow2){
    digitalWrite(yellow1Pin, HIGH); 
  } else {
     digitalWrite(yellow1Pin, LOW);
  }
  
  if (sensorValue > yellow1){
    digitalWrite(green2Pin, HIGH); 
  } else {
     digitalWrite(green2Pin, LOW);
  }
  
  if (sensorValue > green2){
    digitalWrite(green1Pin, HIGH); 
  } else {
     digitalWrite(green1Pin, LOW);
  }
  
                
}







