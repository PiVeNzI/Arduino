// Author of code : Mihael Beljo --- mihaelbeljo0405@gmail.com
// Contact me if you have any questions about this code
// All rights belong to author, but this software code is open sourced for everyone
// Date : 17/4/2020

// Detail info: 
//This code includes Arduino Uno, breadboard, HC-SRO4 sensor, 1602 LCD generic, generic buzzer and basic LED Diode. 
//Distance is calculated in centimeters via Assembly code builted in HC-SRO4 sensor. Speed of sound is 340m/so in
//microseconds so speed in microseconds is 0.0304m/us. You need it to divide by two because sound waves travel
//from sensor to object and back off object to sensor. Sensor sends 8 cycled sonic bursts.


#include <LiquidCrystal.h>


// Here you can change the various ports you used for various parts
LiquidCrystal lcd(6 , 7, 5, 4, 3, 2); 
const int echoPin = 10;
const int trigPin = 11;
const int buzzer = 12;
const int ledPin = 13;

//
long duration;
int distanceCm;
int safetyDistance;


//
void setup() {
  
lcd.begin(16,2); // Here you can change LCD size if you use larger or smaller device, most used one is 1602
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);

}


//
void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


//
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;


//
safetyDistance = distanceCm;
if (safetyDistance <=10) { // Here you can change the distance for buzzer activation 
  digitalWrite(buzzer, HIGH); 
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}


//
lcd.setCursor(0,0); 
lcd.print("Distance:"); // Here you can change text if you need to change it to another language or etc.
lcd.print(distanceCm); 
lcd.print("CM");
delay(10);

}
