#include "DHT.h"
#define Type DHT11
int sensePin = 6;

DHT HT(sensePin,Type);
float humidity;
float Celsius;
float Farenheit;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,INPUT);
  HT.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  Celsius = HT.readTemperature();
  Farenheit = HT.readTemperature(true);
  Serial.print(" Humidity: ");
  Serial.print(humidity);
  Serial.print(", Celsius: ");
  Serial.print(Celsius);
  Serial.print(", Farhenheit: ");
  Serial.println(Farenheit);
  delay(1000);

}
