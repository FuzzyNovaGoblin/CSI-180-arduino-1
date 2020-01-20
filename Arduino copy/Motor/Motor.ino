
/*
SparkFun Tinker Kit
Example sketch 9

SparkFun Motor Driver

Use the SparkFun Motor Driver to control the speed and direction of a motor

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn more about Arduino.
*/

//define the two direction logic pins and the speed / PWM pin
const int DIR_A = 5;
const int DIR_B = 4;
const int PWM = 6;

void setup()
{
//set all pins as output
pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(PWM, OUTPUT);

 

}

void loop()
{

digitalWrite(DIR_A, HIGH);
 digitalWrite(DIR_B, LOW);
 analogWrite(PWM, 255);

 }

