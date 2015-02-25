#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

class Autonomous:public Mode{
  public:
    void start(){
      int bounceEnd=NUM_LEDS/6;
      for(int i=3;i<bounceEnd;i++){
        leds[i-3].r=165,
        leds[i-3].g=255,
        leds[i-3].b=0;
        leds[i-2].r=195,
        leds[i-2].g=255,
        leds[i-2].b=85;
        leds[i-1].r=215,
        leds[i-1].g=255,
        leds[i-1].b=170;
        leds[i].r=255,
        leds[i].g=255,
        leds[i].b=255;
        leds[2*bounceEnd*(i-3)].r=165,
        leds[2*bounceEnd*(i-3)].g=255,
        leds[2*bounceEnd*(i-3)].b=0;
        leds[2*bounceEnd*(i-2)].r=195,
        leds[2*bounceEnd*(i-2)].g=255,
        leds[2*bounceEnd*(i-2)].b=85;
        leds[2*bounceEnd*(i-1)].r=215,
        leds[2*bounceEnd*(i-1)].g=255,
        leds[2*bounceEnd*(i-1)].b=170;
        leds[2*bounceEnd*i].r=255,
        leds[2*bounceEnd*i].g=255,
        leds[2*bounceEnd*i].b=255;
        leds[3*bounceEnd*(i-3)].r=165,
        leds[3*bounceEnd*(i-3)].g=255,
        leds[3*bounceEnd*(i-3)].b=0;
        leds[3*bounceEnd*(i-2)].r=195,
        leds[3*bounceEnd*(i-2)].g=255,
        leds[3*bounceEnd*(i-2)].b=85;
        leds[3*bounceEnd*(i-1)].r=215,
        leds[3*bounceEnd*(i-1)].g=255,
        leds[3*bounceEnd*(i-1)].b=170;
        leds[3*bounceEnd*i].r=255,
        leds[3*bounceEnd*i].g=255,
        leds[3*bounceEnd*i].b=255;
        leds[4*bounceEnd*(i-3)].r=165,
        leds[4*bounceEnd*(i-3)].g=255,
        leds[4*bounceEnd*(i-3)].b=0;
        leds[4*bounceEnd*(i-2)].r=195,
        leds[4*bounceEnd*(i-2)].g=255,
        leds[4*bounceEnd*(i-2)].b=85;
        leds[4*bounceEnd*(i-1)].r=215,
        leds[4*bounceEnd*(i-1)].g=255,
        leds[4*bounceEnd*(i-1)].b=170;
        leds[4*bounceEnd*i].r=255,
        leds[4*bounceEnd*i].g=255,
        leds[4*bounceEnd*i].b=255;
        leds[5*bounceEnd*(i-3)].r=165,
        leds[5*bounceEnd*(i-3)].g=255,
        leds[5*bounceEnd*(i-3)].b=0;
        leds[5*bounceEnd*(i-2)].r=195,
        leds[5*bounceEnd*(i-2)].g=255,
        leds[5*bounceEnd*(i-2)].b=85;
        leds[5*bounceEnd*(i-1)].r=215,
        leds[5*bounceEnd*(i-1)].g=255,
        leds[5*bounceEnd*(i-1)].b=170;
        leds[5*bounceEnd*i].r=255,
        leds[5*bounceEnd*i].g=255,
        leds[5*bounceEnd*i].b=255;
      }
    }
};

#endif
