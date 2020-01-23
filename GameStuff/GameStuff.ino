#include <Esplora.h>
#include <math.h>

const int MAX_SLIDE = 1024;
const int SHIELD_BLOCK_DIS = 341;

bool block;
bool hit;


bool usedSword;
bool usedShield;
bool waitingInput;
bool calc;
int pSword;
int eSword;
int pShield;
int eShield;

void setup() {
  waitingInput = false;
  calc = false;
  pSword = 0;
  eSword = 0;
  pShield = 0; 
  eShield = 0;
  Serial.begin(9600);
}

void loop() {
  int button1 = Esplora.readButton(SWITCH_1);
  int button2 = Esplora.readButton(SWITCH_2);
  int button3 = Esplora.readButton(SWITCH_3);
  int button4 = Esplora.readButton(SWITCH_4);
  
  if(waitingInput){
    if(!usedShield){
      if(button3 == LOW){
        pShield = Esplora.readSlider()+1;
        usedShield = true;
      }
      if(button4 == LOW){
        pShield = (Esplora.readSlider()+1) * -1;
        usedShield = true;
      }
    }
    if(!usedSword){
      if(button2 == LOW){
        pSword = Esplora.readSlider() + 1;
        usedSword = true;
      }
      if(button1 == LOW){
        pSword = (Esplora.readSlider() + 1) * -1;
        usedSword = true;
      }
    }

    if(usedSword && usedShield){
      waitingInput = false;
      usedSword = false;
      usedShield = false;
      //Serial.print("Swing ");
      //Serial.println(pSword);
      //Serial.print("Block ");
      //Serial.println(pShield);
      calc = true;
    }
  }
  else if(calc){
    if(eSword * pShield > 0 ){
     block = abs(pShield - eSword) <= SHIELD_BLOCK_DIS;
    }
    else{
      block = false;
    }
    if(eShield * pSword > 0 ){
     hit = abs(eShield - pSword) > SHIELD_BLOCK_DIS;
    }
    else{
      block = false;
    }

    if(block){
      Esplora.writeRGB(0,0,255);  
    }
    else{
      Esplora.writeRGB(255,0,0);  
    }
    delay(1000);
    if(hit){
      Esplora.writeRGB(0, 255, 0);  
    }
    else{
      Esplora.writeRGB(255,128,0);  
    }
    delay(1000);
    calc = false;
    
  }
  else{
    eShield = (random(MAX_SLIDE)+1) * (bool)random(2) ? -1 : 1;
    eSword = (random(MAX_SLIDE)+1) * (bool)random(2) ? -1 : 1;
    
     Serial.print("Swing ");
     Serial.println(eSword);
     Serial.print("Block ");
     Serial.println(eShield);
    waitingInput = true;
  }

  //int val = Esplora.readSlider();
  //Serial.println(val);
  //delay(500);
}
