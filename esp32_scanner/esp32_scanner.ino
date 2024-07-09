#include <WiFi.h>
#define led 17


void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(1000);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Scanning for Networks");
int n = WiFi.scanNetworks();
if(n!=0){
  digitalWrite(led,HIGH);
  Serial.print("Networks :  "); 
  for(int i ; i<n ; i++){
    Serial.print(WiFi.SSID(i));//wifi name ssid bejiin
    Serial.print("  ");
    Serial.println(WiFi.RSSI(i));//wifi strength idk
    delay(50);
  }
}else{
  Serial.println("No networks found");
}
Serial.println("\n---------------------------------------------------");
delay(4000);
}
