/*
  Arduino Bootcamp
  - LED Reaction Game - Interrupt Demo - Part 1
  This circuit demonstrates how to setup and the execution of an interrupt.
  When a switch that is connected to interrupt pin 2 is pressed, it fires and interrupt which toggles the LED on pin 13
  by: Lee Assam
*/


const int ledPin = 13;
const int inputPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  //recommend
  //attachInterrupt(digitalPinToInterrupt(2), buttonPressed, FALLING);
  //not recommended
  attachInterrupt(0, buttonPressed, FALLING);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void buttonPressed() {
  Serial.println("Interrupt Occured!");
  if(digitalRead(ledPin)) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
}
