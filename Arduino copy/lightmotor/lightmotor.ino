
const int DIR_A = 5;
const int DIR_B = 4;
const int PWM = 6;
const int DIR_C = 10;
const int DIR_D = 9;
const int PMW = 11;
const int sensorPin = 0;
int lightCal;
int lightVal;
int lightvalue;
int a;
int b;

void setup() {

pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(PWM, OUTPUT);
lightCal = analogRead(sensorPin);

pinMode(DIR_C, OUTPUT);
pinMode(DIR_D, OUTPUT);
pinMode(PMW, OUTPUT);

Serial.begin(9600);


}

void loop() {

lightVal = analogRead(sensorPin);

if(lightvalue < lightVal)
{
  a = lightVal;
  Serial.println(a);
  delay(100);
}
if(lightvalue > lightVal)
{
  b = lightVal;
  Serial.println(b);
  delay(100);
}

int val = analogRead(0);
val = map(lightVal, a, b , 0, 255);
  if(lightVal <= a && lightVal >= b)
  {
    digitalWrite(DIR_A, HIGH);
    digitalWrite(DIR_B, LOW);
    analogWrite(PWM, val);

    digitalWrite(DIR_C, HIGH);
    digitalWrite(DIR_D, LOW);
    analogWrite(PMW, val);

  }

  lightvalue = lightVal;
    
}
