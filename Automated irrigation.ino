//Welcome to Electronics University
//Subscribe us if you want to learn something new.

#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

dht DHT;

#define DHT11_PIN 5

int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
int relayPin = 6;

void setup(){
  lcd.begin(16, 2);
  pinMode(sensor_pin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1); 
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);
  
  lcd.setCursor(23,0);
  lcd.autoscroll();
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,10,0,100);
  lcd.print("Mositure: ");
  lcd.print(output_value);
  lcd.print("%");
  
  lcd.setCursor(23,1);
  if(output_value<30){
  digitalWrite(relayPin, LOW);
  lcd.print("Motor ON");
 }
 else
 {
  digitalWrite(relayPin, HIGH);
  lcd.print("Motor OFF");       
 }
  
  delay(2500);
  lcd.noAutoscroll();
  lcd.clear();
}
