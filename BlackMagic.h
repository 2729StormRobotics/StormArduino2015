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
      for(int j=1;j<NUM_LEDS;j++)
      {
        for(int i=1;i<NUM_LEDS-j;i++)
         {
          leds[i]=color;
          leds[i-1]=OFF;
          leds[acc]=color;
          FastLED.show();
        if(acc!=NUM_LEDS-j)
        {
          acc++;
        }else acc=1;
      } 
    }
  }
};
#endif
