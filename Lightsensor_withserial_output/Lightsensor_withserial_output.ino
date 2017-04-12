/*
 
 Parts required:
 photoresistor
 10 kilohm resistor 
 piezo
 
Based on starter kit project 6 code by Scott Fitzgerald
  http://arduino.cc/starterKit
 
 This example code is part of the public domain 
*/

// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;
int adjustedLightLevel = 0;         // variable for lightreading


void setup() {
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
  
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

}

void loop() {
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A0);
  //write the variable to the serial connection
adjustedLightLevel = map(sensorValue, sensorLow, sensorHigh, 0, 100); 
    Serial.print(adjustedLightLevel);
    Serial.write("\n"); 

  // wait for a moment
  delay(1000);
}

