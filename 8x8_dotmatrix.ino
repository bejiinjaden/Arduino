
int R[] = {2,7,A5,5,13,A4,12,A2};  

int C[] = {6,11,10,3,A3,4,8,9};

unsigned char L [8][8] = {

  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},

};

void setup() {
  // put your setup code here, to run once:
for(int i=0; i<8;i++){
  pinMode(R[i],OUTPUT);
  pinMode(C[i],OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
for(int j=0;j<200;j++){
display(L[8][8]);
}
}


void display(unsigned char example[8][8]){

  for(int c=0;c<8;c++){
    digitalWrite(C[c],HIGH);
  
  for(int i=0; i<8;i++){
    digitalWrite(R[i],example[i][c]);
  }
  }
delay(10);
Clear();
}


void Clear() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(R[i], LOW); // Turn off all row LEDs
        digitalWrite(C[i], HIGH); // Deselect all columns
    }
}
