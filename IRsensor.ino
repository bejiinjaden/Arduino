#include<IRremote.h>
int IRpin = 5;
IRrecv IR(IRpin);
decode_results cmd;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:

if(IR.decode(&cmd)){
Serial.println(cmd.value,HEX);
IR.resume();
Serial.println("bejiin");
}
}

