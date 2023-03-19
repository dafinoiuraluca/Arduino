/*
Arduino Bootcamp
  - Simple LED Potentiometer Circuit
This project demonstrates how the brightness of an LED can be controlled by a potentiometer using pulse width modulation
by: Lee Assam
*/

#define LEDPin 9

#define potPin A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //basically with map, you convert values from the range 0 to 1023 in a value between 0 to 255 which are analog values
  //analogWrite can take values only between 0 to 255
  //scalling 
  int reading = map(analogRead(potPin), 0, 1023, 0, 255);
  //Send PWM output to the LED
  analogWrite(LEDPin, reading);
  delay(10);
}
