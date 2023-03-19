/*
Arduino Bootcamp
- Piezo Buzzer Circuit
This project demonstrates how a push  button switch can be used to sound a piezo buzer
by: Lee Assam
*/


#define buzzer 9
//#define push_switch 7

void setup() {
  // put your setup code here, to run once:
  //pinMode(push_switch, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  if(digitalRead(push_switch) == LOW) {
//    tone(buzzer, 2000); 
//  }
//  else {
//    noTone(buzzer);
//  }
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
