const int DIR_A = 5;
const int DIR_B = 4; 
const int PWM = 6;
const int DIR_C = 10;
const int DIR_D = 9;
const int PMW = 11;

void setup() {

pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(PWM, OUTPUT);
pinMode(DIR_C, OUTPUT);
pinMode(DIR_D, OUTPUT);
pinMode(PMW, OUTPUT);

Serial.begin(9600);


}

void loop() {

digitalWrite(DIR_A, LOW);
digitalWrite(DIR_B, HIGH);
analogWrite(PWM, 235);

digitalWrite(DIR_C, HIGH);
digitalWrite(DIR_D, LOW);
analogWrite(PWM, 255);

}
