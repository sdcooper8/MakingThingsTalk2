/*
  Serial RGB LED controller
 Context: Arduino
 
 Controls an RGB LED whose R, G and B legs are 
 connected to pins 3, 5, and 4, of the MKR1000, respectively.
 (for the 101, change these to 3, 6, and 5 respectively)
 
 To control it, type 'r', 'g', or 'b' followed by
 the numerals 0 through 9. Each LED can be set at a brightness level 
 from 0 to 9.
 
 created 19 July 2010
 modified 14 Mar 2016
 by Tom Igoe
 
 */

// constants to hold the output pin numbers:
const int redPin = 3;     // for 101 use 3
const int greenPin = 6;   // for 101 use 6
const int bluePin = 5;    // for 101 use 5


int currentPin = 0; // current pin to be faded
int brightness = 0; // current brightness level

void setup() {
  // initiate serial communication:
  Serial.begin(9600);

  // initialize the LED pins as outputs:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop() {
  // if there's any serial data in the buffer, read a byte:
  if (Serial.available() > 0) {
    int inByte = Serial.read(); 

    // respond to the values 'r', 'g', 'b', or '0' throigh '9'.
    // you don't care about any other value:
    if (inByte == 'r') {
      currentPin = redPin; 
    }
    if (inByte == 'g') {
      currentPin = greenPin; 
    }
    if (inByte == 'b') {
      currentPin = bluePin; 
    } 

    if (inByte >= '0' && inByte <= '9') {
      // map the incoming byte value to the range of the analogRead() command:
      brightness = map(inByte, '0', '9', 0, 255);  
      // set the current pin to the current brightness:
      analogWrite(currentPin, brightness);    
    } 
  }
}

