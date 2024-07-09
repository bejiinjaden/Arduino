#include "BluetoothSerial.h"
BluetoothSerial ESP_32;


void setup() {
  // put your setup code here, to run once:
ESP_32.begin("ESP_32");
Serial.begin(115200);
Serial.println("ESP32 is ready to pair");
}

void loop() {
  // put your main code here, to run repeatedly:
if(ESP_32.available()){
  int info = ESP_32.read();
  Serial.println(info);
  ESP_32.print("Received:");
  ESP_32.println(info);
}else {
    Serial.println("No data received");
  }
delay(5000);
}
