/* 
This is script that runs a motor that opens and closes a set of blinds, revealing an image painted on them  of as part of the Greame Durant Show 
at Baltic December 2014,

Based on a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

unsigned long randomTimeOn;  // here's a variable to store our blinds open time value
unsigned long randomTimeOff;  // here's a variable to store our blinds closed time value


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
   
  randomSeed(analogRead(0)); // start the random call in a unspecified point in the random sequence
  myMotor->setSpeed(50);  // 600 rpm 
  myMotor->release(); // stop rotation and turn off holding torque.
}

void loop() {
  
  randomTimeOn = random(0, 4000); // this then randomly picks a number in the range specified
  Serial.println(randomTimeOn); // what number 'randomTime' is holding
  Serial.println("Double coil steps");
  myMotor->step(155, FORWARD, DOUBLE); 
  myMotor->release();
  delay(randomTimeOn);
  randomTimeOff = random(0, 4000);  // chose a differnet number within the range specified
  myMotor->step(155, BACKWARD, DOUBLE);
  myMotor->release();
  delay(randomTimeOff);  

}
