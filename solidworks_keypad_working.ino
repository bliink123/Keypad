
#include <Keypad.h> //http://playground.arduino.cc/Code/Keypad
#include <Keyboard.h>

const byte ROWS = 4;
const byte COLS = 4;

char Keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
 };

//keypad pin to arduino pins
//keypad pin 5 to digital 5
//keypad pin 6 to digital 4
//keypad pin 7 to digital 3
//keypad pin 8 to digital 2
//keypad pin 1 to digital 9
//keypad pin 2 to digital 8
//keypad pin 3 to digital 7
//keypad pin 4 to digital 6
 
// set pin numbers:
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

const int modeButton1 = A1;   // the number of the pushbutton pin in pulldown configuration
const int modeButton2 = A2;

const int ledPin1 =  A3;      // the number of the LED pin
const int ledPin2 =  A4; 

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

// variables that will change:
int buttonState1 = 0;        // variable for reading the pushbutton state
int buttonState2 = 0;

int modeVar = 0;             // variable for selecting mode

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

//modeVar will set button 1 and 2 into either mode1 or mode2, this changes which button
//lights up which LED. The if states to light LED 1 and 2 checks against 2 boolean values
// to be true, button state and modeVar value.

void setup() {
  
  Keyboard.begin(); // Start communication
  delay(2000); // Wait for device to be found as a Keyboard
  
   // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(modeButton1, INPUT);
  pinMode(modeButton2, INPUT);
}

void loop() {
	
 char key = customKeypad.getKey();
	
 // read the state of the pushbutton value:
  buttonState1 = digitalRead(modeButton1);
  buttonState2 = digitalRead(modeButton2);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
 
//---MODE SETTINGS---
  if (buttonState1 == HIGH) {            //if button1 is pressed mode will be set to 1 and led2 is cleared
    digitalWrite(ledPin2, LOW);
    modeVar = '1'; 
  }

  if (modeVar == '1') {                 //if mode is 1 led1 will be lit
    analogWrite(ledPin1, outputValue);
	 if (key != NO_KEY && key != 'x'){
	 if     (key == '1'){Keyboard.print("1");}
    else if(key == '2'){Keyboard.print("2");}
    else if(key == '3'){Keyboard.print("3");}
    else if(key == '4'){Keyboard.print("4");}
    else if(key == '5'){Keyboard.print("5");}
    else if(key == '6'){Keyboard.print("6");}
    else if(key == '7'){Keyboard.print("7");}
    else if(key == '8'){Keyboard.print("8");}
    else if(key == '9'){Keyboard.print("9");}
    else if(key == '0'){Keyboard.print("0");}
    else if(key == '*'){Keyboard.print("*");}
    else if(key == '#'){Keyboard.print("#");}
    else if(key == 'A'){Keyboard.print("A");}
    else if(key == 'B'){Keyboard.print("B");}
    else if(key == 'C'){Keyboard.print("C");}
    else if(key == 'D'){Keyboard.print("D");}
  }
  }  
    
  if (buttonState2 == HIGH) {           //if button2 is pressed mode will be set to 2 and led1 is cleared
    digitalWrite(ledPin1, LOW);
    modeVar = '2';
  } 

  if (modeVar == '2') {                 //if mode is 2 led2 will be lit
    analogWrite(ledPin2, outputValue);
	 if (key != NO_KEY && key != 'x'){
    if     (key == '1'){Keyboard.print("a");}
    else if(key == '2'){Keyboard.print("b");}
    else if(key == '3'){Keyboard.print("c");}
    else if(key == '4'){Keyboard.print("d");}
    else if(key == '5'){Keyboard.print("e");}
    else if(key == '6'){Keyboard.print("f");}
    else if(key == '7'){Keyboard.print("g");}
    else if(key == '8'){Keyboard.print("h");}
    else if(key == '9'){Keyboard.print("i");}
    else if(key == '0'){Keyboard.print("j");}
    else if(key == '*'){Keyboard.print("k");}
    else if(key == '#'){Keyboard.print("l");}
    else if(key == 'A'){Keyboard.print("w");}
    else if(key == 'B'){Keyboard.print("x");}
    else if(key == 'C'){Keyboard.print("y");}
    else if(key == 'D'){Keyboard.print("z");}
   }
  }
}
