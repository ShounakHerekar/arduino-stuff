#include <LiquidCrystal.h>
#define trigPin1 10
#define trigPin 9
#define echoPin 8
#define echoPin1 7
#define buzzer 6
long duration;
int distancef;
int distanceb;
// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
 // set up the LCD's number of columns and rows:
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
 pinMode(buzzer, OUTPUT); // Sets buzzer as an output
 Serial.begin(9600); // Starts the serial communication
 lcd.begin(16, 2); // Starts the lcd
 lcd.print("F_Distance:");
 lcd.setCursor(0, 1);
 lcd.print("B_Distance:");
 lcd.setCursor(0, 1);
}
void loop() {
 //Code For measuring forward distance

 digitalWrite(trigPin, LOW);
 delayMicroseconds(10);
 // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin, HIGH);
 // Calculating the distance
 distancef = (duration * 0.034 / 2);
 // Prints the distance on the Serial Monitor
 Serial.print("Distance: ");
 Serial.print(distancef);
 Serial.println(" cm");
 //Code for measuring backward distance
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(10);
 // Sets the trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin1, HIGH);
 // Calculating the distance
 distanceb = (duration * 0.034 / 2);
 // Prints the distance on the Serial Monitor
 Serial.print("Distance: ");
 Serial.print(distanceb);
  Serial.println(" cm");
 // Logic behind this code

 if(distancef > 15)
 {
 lcd.setCursor(12, 0);
 lcd.print(distancef);
 lcd.print("cm");
 }
 else
 {
 digitalWrite(buzzer,HIGH);
 delay(1000);
 digitalWrite(buzzer,LOW);
 lcd.setCursor(12, 0);
 lcd.print("stop");
 Serial.print("stop ");
 }
 if(distanceb > 15)
 {
 lcd.setCursor(12, 1);
 lcd.print(distanceb);
 lcd.print("cm");
 }
 else
 {
 digitalWrite(buzzer,HIGH);
 delay(1000);
 digitalWrite(buzzer,LOW);
 lcd.setCursor(12, 1);
 lcd.print("stop");
 }
  if(distancef < 15 && distanceb < 15)
 {
 digitalWrite(buzzer,HIGH);
 delay(1000);
 digitalWrite(buzzer,LOW);
 lcd.setCursor(12, 1);
 lcd.print("stop");
 lcd.setCursor(12, 0);
 lcd.print("stop");
 }
 delay(500);
}
