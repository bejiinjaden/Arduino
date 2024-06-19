#include <IRremote.h>

int IRPin = 7;
IRrecv IR (IRPin);
decode_results cmd;

void setup() {
  Serial.begin(9600);    // Initialize serial communication at 9600 baud rate
  IR.enableIRIn();       // Start the IR receiver
}

void loop() {
  if (IR.decode(&cmd)) {          
    Serial.println(cmd.value, HEX);
    Serial.print("god");
    IR.resume();   
                    
  }
}