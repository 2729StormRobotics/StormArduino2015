#ifndef DISABLED_H
#define DISABLED_H

#include "common.h"

class Disabled:public Mode{
  public:
    void start(){
      for(int i=0;i<=NUM_LEDS;i++){
        leds[i].r=204;
        leds[i].g=255;
        leds[i].b=153;
        FastLED.show();
      }
    }
};
#endif
