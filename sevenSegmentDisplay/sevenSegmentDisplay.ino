/*
Arduino Bootcamp
- Using a Seven Segment Display
  This project demonstrates how to set up a seven segment display


  - Digital Dice
  This project uses a seven segment display to create a digital dice
by: Lee Assam
*/
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};

byte digits[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, //0 
  {0, 1, 1, 0, 0, 0, 0, 0}, //1
  {1, 1, 0, 1, 1, 0, 1, 0}, //2
  {1, 1, 1, 1, 0, 0, 1, 0}, //3 
  {0, 1, 1, 0, 0, 1, 1, 0}, //4
  {1, 0, 1, 1, 0, 1, 1, 0}, //5 
  {1, 0, 1, 1, 1, 1, 1, 0}, //6 
  {1, 1, 1, 0, 0, 0, 0, 0}, //7
  {1, 1, 1, 1, 1, 1, 1, 0}, //8
  {1, 1, 1, 1, 0, 1, 1, 0} //9
};

  byte spinDigits [6][8] = {
    //  a  b  c  d  e  f  g
    { 1, 0, 0, 0, 0, 0, 0, 0}, // a
    { 0, 1, 0, 0, 0, 0, 0, 0}, // b
    { 0, 0, 1, 0, 0, 0, 0, 0}, // c
    { 0, 0, 0, 1, 0, 0, 0, 0}, // d
    { 0, 0, 0, 0, 1, 0, 0, 0}, // e
    { 0, 0, 0, 0, 0, 1, 0, 0}  // f
};

#define button 9

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }
//  Serial.begin(9600);
//  Serial.println("Enter a number between 0 and 9: ");

  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
//  if(Serial.available()){
//    char ch = Serial.read();
//    if(ch >= '0' && ch <= '9') {
//      int number = ch - '0';
//      updateDisplay(number);
//    }
//  }

  if(digitalRead(button) == LOW){
    spin();
    roll();
    delay(500);
  }
}

void roll() {
  int roll = random(1, 7);
  updateDisplay(roll);
}

void updateDisplay(int value){
  setSegments(value);
}

void spin(){
  for(int j = 0; j < 6; j++) {
    for(int i = 0; i < 8; i++) {
      digitalWrite(segmentPins[i], spinDigits[j][i]);
    }
    delay(250);
  }
}

void setSegments(int n){
  for(int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}





  
