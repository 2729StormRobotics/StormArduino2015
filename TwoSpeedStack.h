#ifndef TWO_SPEED_STACK_H
#define TWO_SPEED_STACK_H

#include "common.h"
//What do? Well it sends a particle down. Once it gets halfway down the unlit strip, it sends another.
//once one of these particles get down to the end, it stays and any particles that come to it stack on top
//of the one already there
class TwoSpeedStack:public Mode{
  public:
    void start(){
      CRGB color;
      color.r=255,
      color.g=255,
      color.b=255; 
     leds[0]=color; //because the i loop variable starts at 1.
     int acc;  //here to send 2 at once
     boolean first=true;//not a fan of this practice but whatevs
      for(int j=0;j<NUM_LEDS;j++) //this makes it so the loops end at one less LED each time
      {
        for(int i=1;i<(NUM_LEDS)-j;i++) //one of the two particles
        {
          if(i>NUM_LEDS/2-j&&first) //acc does not become activated until i becomes half the strips value
          {       
             acc=1;                       
             first=false;        //makes sure it doesn't come through the loop again until this whole start method ends again
          }                               
       leds[i]=color;
       leds[i-1]=OFF;
       if(!first){
         leds[acc]=color;  //if acc is allowed to be used, go ahead and accumulate acc.
         leds[acc-1]=OFF;
       }
        FastLED.show();

       if(acc!=NUM_LEDS-j-1)  //if acc is not at the end of the empty strip, accumulate it
       {
         acc++;
       }
     else
   { 
     acc=1;    //if acc is, send it back to the beginning and increase that stack value by one
     j++;
 }

       }
     }
    }
  
};
#endif
