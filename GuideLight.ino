#include <arduino.h>

unsigned long pretime;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(7,HIGH);
  pretime = millis();
}

void loop() {
  static int state = 0;
  if((millis() - pretime) >= 500){
    pretime = millis();
    digitalWrite(7,!digitalRead(7));  // 警告灯
    digitalWrite(8,!digitalRead(8));  // 警告灯
    
    switch(state){ // 視線誘導灯
      case 0:
              digitalWrite(9,HIGH);
              digitalWrite(10,LOW);
              digitalWrite(11,LOW);
              state = 1;
              break;
      case 1:
              digitalWrite(9,LOW);
              digitalWrite(10,HIGH);
              digitalWrite(11,LOW);
              state = 2;
              break;                    
      case 2:
              digitalWrite(9,LOW);
              digitalWrite(10,LOW);
              digitalWrite(11,HIGH);
              state = 0;
              break;  
      default:
              break;
    }
  }
}
