int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(touchRead(T7));
if(touchRead(T4) < 30){
  digitalWrite(ledPin,HIGH);
}else{
  digitalWrite(ledPin,LOW);
}
delay(200);

}
