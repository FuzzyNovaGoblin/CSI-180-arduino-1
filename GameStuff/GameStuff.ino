#include <Esplora.h>

const int MAX_SLIDE = 1023;
const int SHIELD_BLOCK_DIS = 57;


bool usedSword;
bool usedShild;
bool waiting;
int pSword;
int eSword;
int pShield;
int eShield;

void setup() {
  waiting = false;
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
  
  if(waiting){
    if(!usedShild && (button3 == LOW || button4 == LOW)){
      
    }
  }
  else{
    eShield = random(MAX_SLIDE+1) * (bool)random(2) ? -1 : 1;
    eSword = random(MAX_SLIDE+1) * (bool)random(2) ? -1 : 1;
    waiting = true;
  }

  int val = Esplora.readSlider();
  Serial.println(val);
  delay(500);
}
