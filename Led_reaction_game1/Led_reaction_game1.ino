/*
Arduino Bootcamp
- LED Reaction Game - Part 2
This project demonstrates a reaction game with LEDs. The objective is to push the switch when the Red LED is lit
by: Lee Assam
*/


#define greenLed 8
#define redLed 9
#define yellowLed 10

//random set of times for the LEDs to be lit
int timesOn[] = {100, 250, 400, 500};
//random delays between LEDs being lit
int delayTimes[] = {250, 500, 1000, 1500};

//Declaring volatile variables so they can be accessed/changed within the ISR
volatile boolean redLEDLit = false;
volatile boolean isWinner = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  //creating interrupt
  attachInterrupt(0, checkWinner, FALLING);
  //Turn off LEDs
  turnOffLEDs();
}

void loop() {
  // put your main code here, to run repeatedly:

  //randomly determine which led to be lit
  int LEDtoLight = random(1, 4);

  //determine a random time for the LED to be lit
  int periodLEDlit = timesOn[random(4)];

  //light the respective LED
  lightLED(LEDtoLight, periodLEDlit);

  //turn off the LEDs
  turnOffLEDs();

  //delay for a random time after the LEDs are turnned off - makes the game unpredictable
  int delayTime = delayTimes[random(4)];
  delay(delayTime);

  //check winner flag for a winner
  if(isWinner) {
    isWinner = false;
    Winner();
  }
}

void lightLED(int led, int duration){
   switch(led) {
    case 1: //green
      digitalWrite(greenLed, HIGH);
      break;

    case 2: //red
      digitalWrite(redLed, HIGH);
      break;

   case 3: //yellow
      digitalWrite(yellowLed, HIGH);
      break;

   default: 
      break;
   }
   //wait the duration
   delay(duration);
   //reset redLEDLit flag
   redLEDLit = false;
}

void turnOffLEDs() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
}

//Flashes 3 times in a row to indicate a win
void Winner() {
  for(int i = 0; i < 3; i++) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    delay(250);    
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW); 
    delay(250);   
  }
  delay(3000);
}

void checkWinner() {
  if(redLEDLit) {
    //set Winner flag
    isWinner = true;
  }
}
