#ifndef BLACK_MAGIC_H
#define BLACK_MAGIC_H

#include "common.h"

class BlackMagic:public Mode
  {
  public:
    void start()
    {
      CRGB color;
      color.r=0,
      color.g=255,
      color.b=255;//that straight up purp
      leds[0]=color;//because i starts at one
      FastLED.show();
      boolean first=true;
      int acc=0;     
        for(int i=0;i<NUM_LEDS/2;i++){
          leds[i]=color;
          leds[NUM_LEDS-i]=color;
          FastLED.show();
      } 
      for(int i=0;i<NUM_LEDS/2;i++){
        leds[NUM_LEDS/2-i]=OFF;
        leds[NUM_LEDS/2+i]=OFF;
        FastLED.show();
      }
      
      
  }
    
};
#endif
