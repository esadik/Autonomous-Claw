#include <NewPing.h>      // include the NewPing library for this program
#define VCC_PIN 13
#define TRIGGER_PIN 12    // sonar trigger pin will be attached to Arduino pin 12
#define ECHO_PIN 11       // sonar echo pint will be attached to Arduino pin 11
#define GROUND_PIN 10
#define MAX_DISTANCE 200  // fmaximum distance set to 200 cm
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // initialize NewPing

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() //do the following things once

{
  pinMode(ECHO_PIN, INPUT) ;  
  pinMode(TRIGGER_PIN, OUTPUT) ;
  pinMode(GROUND_PIN, OUTPUT);    // tell pin 10 it is going to be an output
  pinMode(VCC_PIN, OUTPUT);       // tell pin 13 it is going to be an output
  digitalWrite(GROUND_PIN,LOW);   // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(VCC_PIN, HIGH) ;   // tell pin 13 to output HIGH (+5V)

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() // do the following things forever

{
  delay(100);                             // wait for this number of milliseconds
  int DISTANCE_IN_CM = sonar.ping_cm();   // read the sonar sensor, using a variable
  
  if( 1<DISTANCE_IN_CM && DISTANCE_IN_CM <=10 ) {//*will add a delay in the future for time to move down to object from distance

      for(pos = 0; pos < 180; pos += 1){ // goes from 0 degrees to 180 degrees  // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15 ms for the servo to reach the position
      }                                
      delay(3000);
      for(pos = 180; pos > 0; pos -= 1){ // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15 ms for the servo to reach the position
      }
      delay(3000);
    }
    
 }
 
