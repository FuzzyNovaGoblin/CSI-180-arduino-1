



//The setup function runs once upon your Arduino being powered or once upload is          //complete.

void setup()
{
  //set pin 13 to OUTPUT 
  pinMode(13, OUTPUT);
}

//The loop function runs from the top down and repeats itself until you upload new        //code or power down your Arduino
void loop()
{
  //Turn pin 13 HIGH (ON). 
  digitalWrite(13, HIGH);   

  //wait 1000 milliseconds (1 second)
  delay(250);

  digitalWrite(13, LOW);

  delay(250);

  digitalWrite(13, HIGH);

  delay(250);

  //Turn pin 13, LOW (OFF)
  digitalWrite(13, LOW);    

  //wait 1000 milliseconds
  delay(1000);  

}

