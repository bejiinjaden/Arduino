#include <Servo.h>
Servo myServo;
int servoAngle;
int xPin = A0;
int yPin = A1;
int xVal;
int yVal;
int trigPin = 6;
int echoPin = 7;
float pingTravel;
float distance;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myServo.attach(13);
pinMode(13,INPUT);
pinMode(xPin,INPUT);
pinMode(yPin,INPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
xVal = analogRead(xPin);
yVal = analogRead(yPin);

if(xVal > yVal){
  servoAngle = map(xVal,0,1023,0,180);
  myServo.write(servoAngle);
  Serial.println(servoAngle);
}else {
  servoAngle = map(yVal,0,1023,0,180);
  myServo.write(servoAngle); 
  Serial.println(servoAngle);
}

distance = Hc();
Serial.print("Distance : ");
Serial.println(distance);


}

float Hc(){
  digitalWrite(trigPin,LOW);
  delay(10);
  digitalWrite(trigPin,HIGH);
  delay(30);
  digitalWrite(trigPin , LOW);
  pingTravel = pulseIn(echoPin,HIGH);
  //Serial.print(pingTravel);
  Serial.println(": Ping");

  //distance = 343 * (pingTravel/1000000*2);//meters/second-i guess so
  distance = (pingTravel * 0.0343) / 2;//cm / microseconds


  delay(1000);

  return distance;

  
}
