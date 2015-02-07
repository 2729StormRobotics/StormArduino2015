#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

#include "common.h"
//what does this look like? well there are no leds at start
//two particles from either side are sent to the middle, where they collide and stay as 1 or 2 leds(1 if odd, 2 if even).
//another two particles are sent and then "stack" on top of the old ones, meaning if there was 1 before, now there are three
//(two from each side). This goes on until the end until a null particle comes and clears it all out except for the middle
class DoubleStack:public Mode{
    public:
      void start(){
        CRGB color;
        for(int j=0;j<NUM_LEDS;j++){
        color.r=random(256),//every time a new particle is sent a new
        color.g=random(256),//color for the particle is assigned randomly
        color.b=random(256);//potentially worth changing, or making a new method based off same idea
           for(int i=1;i<NUM_LEDS/2-j;i++){
             leds[i]=color;
             leds[i-1].r=0,          //set previous led to 0
             leds[i-1].b=0,
             leds[i-1].g=0;
             leds[NUM_LEDS-i]=color;  //NUM_LEDS-i should be i's opposite
             leds[NUM_LEDS-i+1].r=0,  
             leds[NUM_LEDS-i+1].b=0,  //set previous led to 0
             leds[NUM_LEDS-i+1].g=0;
             FastLED.show();
           }
        }
        color.r=0,    //set value of LEDs to
        color.g=0,    //off value
        color.b=0;
           for(int i=0;i<NUM_LEDS/2-1;i++){//minus 1 indicates ignore middle LED(s)
             leds[i]=color;
             FastLED.show();                    
           }                                    
           for(int k=NUM_LEDS;k>NUM_LEDS/2+1;k--){//same deal with plus 1 as with the previous for loop
             leds[k]=color;
             FastLED.show();                       //can't do at same time because of different ending bound
           }
        }
};
#endif
