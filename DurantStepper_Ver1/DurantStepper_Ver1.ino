/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
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

unsigned long randomTime;  // here's a variable to store our delay value
unsigned long a; // a variable to hold the bottom number of the picking range
unsigned long b; // a variable to hold the top number of the picking range

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
   
  randomSeed(analogRead(0)); // start the random call in a unspecified point in the random sequence
  myMotor->setSpeed(600);  // 600 rpm 
  myMotor->release(); // stop rotation and turn off holding torque.
}

void loop() {
  a = random(0, 500); // this randomly picks a number between 0 and 500 and assigns it to variable 'a'
  b = random(1000, 3000); // this randomly picks a number between 500 and 10000 and assigns it to variable 'b'
  randomTime = random(a, b); // this then randomly picks a number between the range dictated by 'a' and 'b'
  
  Serial.println(a); // what number 'a' is holding
  Serial.println(b); // what number 'b' is holding
  Serial.println(randomTime); // what number 'randomTime' is holding
  delay (50); 
  
  delay(randomTime); // delay for the random amount of time sitting in the 'randomTime' variable
  randomTime = random(a, b);  // chose a differnet number within the range specified by variable 'a' and variable 'b'
  Serial.println(randomTime);  // // what number 'randomTime' is holding now
  delay(randomTime);  // delay for the random amount of time sitting in the 'randomTime' variable
  
  Serial.println("Double coil steps");
  myMotor->step(250, FORWARD, DOUBLE); 
  myMotor->release();
  delay(randomTime);
  randomTime = random(a, b);  // chose a differnet number within the range specified by variable 'a' and variable 'b'
  myMotor->step(250, BACKWARD, DOUBLE);
  myMotor->release();
  delay(randomTime);
  

}
