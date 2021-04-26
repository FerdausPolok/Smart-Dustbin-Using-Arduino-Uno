#include <Servo.h>
Servo servoMain; // Define our Servo
int trigpin = 10; // Trigger Pin
int echopin = 11; //Echo Pin 
int lightpin = 6; // LED pin
int distance; // For Calculationg the Distance
float duration; // For Calculationg the Duration
float cm;

void setup()
{
    servoMain.attach(9); // servo on digi pin 9
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    pinMode(lightpin, OUTPUT);
}


void loop()
{ 
  digitalWrite(trigpin, LOW); //Resetting the Trigpin
  delay(2);  
  digitalWrite(trigpin, HIGH); //Sending Ultrasonic Wave
  delayMicroseconds(10);  
  digitalWrite(trigpin, LOW);  //Turning off sending Wave
  duration = pulseIn(echopin, HIGH);  //Measuring duration
  cm = (duration/58.82); // Cinverting in cm
  distance = cm; // Having our Distance
  
  if(distance<30) //If someone is in a range of 0-30 cm
  {
    digitalWrite(lightpin, HIGH); //Turn on the light
    servoMain.write(80);  // Turn Servo 80 degreeS
    delay(5000); 
    digitalWrite(lightpin, LOW); //Turn off the Lights
  }
   else{
     servoMain.write(0); //do nothing
     delay(50); 
     digitalWrite(lightpin, LOW); //Turn off the Lights
   }
}
