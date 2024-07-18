#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <DHT.h>

WebServer server(80);
DHT dt(16,DHT11);

float humidity;
float celsius;
float farenheit;

const char *ssid = "RH-2.4G-A41C80";
const char *password = "44953BA41C80";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dt.begin();
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,password);

while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print("."); 
}

Serial.println("-----------------------");
Serial.print("Connected to: ");
Serial.println(ssid);
Serial.print("IP Address: ");
Serial.println(WiFi.localIP());

if(MDNS.begin("esp32")){
  Serial.println("MDNS responder Started");
}

server.on("/",handleRoot);
server.begin();
Serial.println("HTTP is started");
}



void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
  delay(2);
}

void handleRoot() {
  char msg[1500];

         

  snprintf(msg, 1500,
           "<html>\
  <head>\
    <meta http-equiv='refresh' content='4'/>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.7.2/css/all.css' integrity='sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr' crossorigin='anonymous'>\
    <title>ESP32 DHT Server</title>\
    <style>\
    html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: center;}\
    h2 { font-size: 3.0rem; }\
    p { font-size: 3.0rem; }\
    .units { font-size: 1.2rem; }\
    .dht-labels{ font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px;}\
    </style>\
  </head>\
  <body>\
      <h2>ESP32 DHT Server!</h2>\
      <p>\
        <i class='fas fa-thermometer-half' style='color:#ca3517;'></i>\
        <span class='dht-labels'>Temperature</span>\
        <span>%.2f</span>\
        <sup class='units'>&deg;C</sup>\
      </p>\
      <p>\
        <i class='fas fa-tint' style='color:#00add6;'></i>\
        <span class='dht-labels'>Humidity</span>\
        <span>%.2f</span>\
        <sup class='units'>&percnt;</sup>\
      </p>\
  </body>\
</html>",
           readTemperature(), readHumidity());  

  server.send(200, "text/html", msg);
}

float readTemperature(){
celsius = dt.readTemperature();
if(isnan(celsius)){
  Serial.println("Failed to read the temperature");
  return 0;
}else{
  Serial.println(celsius);
  return celsius;
}
}


float readHumidity(){
  humidity = dt.readHumidity();
if(isnan(humidity)){
  Serial.println("Failed to read the humidity");
  return 0;
}else{
  Serial.println(humidity);
  return humidity;
}
}
