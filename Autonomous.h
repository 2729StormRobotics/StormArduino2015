#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

class Autonomous:public Mode{
  public:
    void start(){
      for(int i=0;i<NUM_LEDS;i++){
        leds[i].r=255;
        leds[i].g=255;
        leds[i].b=255;
      }
    }
};

#endif
