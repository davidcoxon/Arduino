/*glitchy version of the code for the Glitching LED's in the Greame Durant Show 
at Baltic December 2014, essentially this reduced the range of the off time forcing it to be between 200 and 600, while using a squared number for the ontime keeping the upper and lower limits but having fewer variables between favouring more pronouced differences
 */

/*Hacked from Blink code by Peter Evans
  Turns on an LED on for one second, then off for one second, repeatedly.
   Not anymore it doesn't, instead it turns it on and off at variable time delays)
  */
  
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
unsigned long randomTimeOn; // here'sa variable to hold the random number for on time value
unsigned long randomTimeOnSquared;  // here's a variable to store our led on time squared value this changes the nature of the value to favour shorter periods
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
   randomTimeOn = random(0, 100); // this then randomly picks a number in the range specified
   randomTimeOnSquared = randomTimeOn * randomTimeOn; // this squares the random number value
  Serial.println(randomTimeOnSquared); // what number 'randomTime' is holding
  delay (50); 
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(randomTimeOnSquared); // delay for the random amount of time sitting in the 'randomTimeOn' variable
  randomTimeOff = random(400, 800);  // chose a differnet number within the range specified
  Serial.println(randomTimeOff);  // // what number 'randomTimeOff' is holding
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(randomTimeOff);  // delay for the random amount of time sitting in the 'randomTimeOff' variable
}
