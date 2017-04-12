/*glitchy version of the simplified code for the Glitching LED's in the Greame Durant Show 
at Baltic December 2014, essentially uses the square root of the random number to biast towards longer durations for the on time. The off time is restricting to a smaller set of random numbers to replicate a real starter block in a tube light system.
 */

/*Hacked from Blink code by Peter Evans
  Turns on an LED on for one second, then off for one second, repeatedly.
   Not anymore it doesn't, instead it turns it on and off at variable time delays)
  */
  
// Pin 12 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
unsigned long randomTimeOn; // here'sa variable to hold the random number for on time value
unsigned long randomTimeOnRoot;  // here's a variable to store our led on time squared value this changes the nature of the value to favour shorter periods
unsigned long randomTimeOff;  // here's a variable to store our led off time delay value

// the setup routine runs once when you press reset:

void setup() {      
  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  
  Serial.begin(9600); // for troubleshooting to see what numbers are firing out in the serial monitor if there's any issues.
  randomSeed(analogRead(0)); // start the random call in a unspecified point in the random sequence
}

// the loop routine runs over and over again forever:
void loop() {
   randomTimeOn = random(0, 1000000); // this then randomly picks a number in the range specified
   randomTimeOnRoot = sqrt(randomTimeOn); // this squares the random number value
  Serial.println(randomTimeOnRoot); // what number 'randomTime' is holding
  delay (50); 
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(randomTimeOnRoot); // delay for the random amount of time sitting in the 'randomTimeOn' variable
  randomTimeOff = random(400, 1000);  // chose a differnet number within the range specified
  Serial.println(randomTimeOff);  // // what number 'randomTimeOff' is holding
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(randomTimeOff);  // delay for the random amount of time sitting in the 'randomTimeOff' variable
}
