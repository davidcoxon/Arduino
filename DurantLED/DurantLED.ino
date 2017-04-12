/*Hacked from Blink code by Peter Evans
  Turns on an LED on for one second, then off for one second, repeatedly.
   Not anymore it doesn't, instead it turns it on and off at variable time delays)
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

unsigned long randomTime;  // here's a variable to store our led on time value
unsigned long randomTime2;  // here's a variable to store our led off time delay value
unsigned long a; // a variable to hold the bottom number of the picking range
unsigned long b; // a variable to hold the top number of the picking range

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT); 
  
  Serial.begin(9600); // for troubleshooting to see what numbers are firing out in the serial monitor if there's any issues.
  randomSeed(analogRead(0)); // start the random call in a unspecified point in the random sequence
}

// the loop routine runs over and over again forever:
void loop() {
  a = random(0, 100); // this randomly picks a number between 0 and 500 and assigns it to variable 'a'
  b = random(500, 1000); // this randomly picks a number between 500 and 10000 and assigns it to variable 'b'
  randomTime = random(a, b); // this then randomly picks a number between the range dictated by 'a' and 'b'
  
  Serial.println(a); // what number 'a' is holding
  Serial.println(b); // what number 'b' is holding
  Serial.println(randomTime); // what number 'randomTime' is holding
  delay (50); 
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(randomTime); // delay for the random amount of time sitting in the 'randomTime' variable
  randomTime2 = random(a, b);  // chose a differnet number within the range specified by variable 'a' and variable 'b'
  Serial.println(randomTime2);  // // what number 'randomTime' is holding now
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(randomTime2);  // delay for the random amount of time sitting in the 'randomTime' variable
}
