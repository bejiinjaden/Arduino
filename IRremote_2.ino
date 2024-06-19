#include<IRremote.h>
int IRpin = 7;
IRrecv IR(IRpin);
decode_results cmd;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
pinMode(7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(IR.decode(&cmd)==0){

  }
  Serial.println(cmd.value,HEX);
  Serial.println("BEjiin");
  delay(1500);
  IR.resume();

}
