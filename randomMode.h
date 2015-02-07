#include "common.h"

class randomMode: public Mode {
  public:
    void start(){
      //super simple code           /////////////////////////////
      for(int i=0; i<NUM_LEDS;i++){ //go through every led     //
        leds[i].r=random(256),      //set rgb to random value  //
        leds[i].g=random(256),      //from 0 to 255.           //
        leds[i].b=random(256);      /////////////////////////////
      }
      delay(100); //wait a tenth of a second
      FastLED.show();
    }
  
};  


