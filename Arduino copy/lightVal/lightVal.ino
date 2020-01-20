const int sensorPin = 0;
int lightCal;
int lightVal;
void setup() {

lightCal = analogRead(sensorPin);

Serial.begin(9600);

}

void loop() {

lightVal = analogRead(sensorPin);


Serial.println( lightVal );

delay(1000);
}
