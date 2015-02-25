#ifndef RAINBOW_DANCE_PARTY_H
#define RAINBOW_DANCE_PARTY_H

#include "common.h"
//this is going to look totally bangin

class RainbowDanceParty:public Mode{
  public:
    void start(){
      int maxim=NUM_LEDS/2;//Theres enough mention of it to warrant its own declaraion
      if(maxim%2==1){
        leds[maxim-1].r=132,
        leds[maxim-1].g=112,
        leds[maxim-1].b=255;
        leds[maxim].r=148,      //CREATE THE SINGULARITY
        leds[maxim].g=0,        //CREATE IF ODD
        leds[maxim].b=211;
        leds[maxim+1].r=132,
        leds[maxim+1].g=112,
        leds[maxim+1].b=255;
      }else{                
        leds[maxim-1].r=132,
        leds[maxim-1].g=112,
        leds[maxim-1].b=255;
        leds[maxim].r=148,      //CREATE IF EVEN
        leds[maxim].g=0,
        leds[maxim].b=211;
        leds[maxim+1].r=148,
        leds[maxim+1].g=0,
        leds[maxim+1].b=211;
        leds[maxim+2].r=132,
        leds[maxim+2].g=112,
        leds[maxim+2].b=255;
      }
      FastLED.show();
      for(byte i=1;i<maxim;i++){
        leds[i].r=255,
        leds[i].b=255,
        leds[i].g=255;
        leds[i-1].r=0,
        leds[i-1].b=0,
        leds[i-1].g=0;          //HERE COME THE DOUBLE PARTICLES
        leds[NUM_LEDS-i].r=255,
        leds[NUM_LEDS-i].b=255,
        leds[NUM_LEDS-i].g=255;
        leds[NUM_LEDS-i+1].r=0,
        leds[NUM_LEDS-i+1].b=0,
        leds[NUM_LEDS-i+1].g=0;
        FastLED.show();
        delay(5);//DRAMATIC EFFECT
      }
      double changeFactor=255/(maxim/6);
      for(byte i=1;i<maxim/6;i++){
        leds[maxim+i].g=255;
        leds[maxim+i].r=changeFactor*i;
        leds[maxim+i].b=0;
        
        leds[maxim-i].g=255;
        leds[maxim-i].r=changeFactor*i;
        leds[maxim-i].b=0;
        FastLED.show();
      }
      for(byte i=maxim/6;i<maxim/3;i++){
        leds[maxim+i].g=255-(changeFactor*i);
        leds[maxim+i].r=255;
        leds[maxim+i].b=0;
        
        leds[maxim-i].g=255-(changeFactor*i);
        leds[maxim-i].r=255;
        leds[maxim-i].b=0;
        FastLED.show();
      }
      for(byte i=maxim/3;i<maxim/2;i++){
        leds[maxim+i].g=0;
        leds[maxim+i].r=255;
        leds[maxim+i].b=changeFactor*i;
        
        leds[maxim-i].g=0;
        leds[maxim-i].r=255;
        leds[maxim-i].b=changeFactor*i;
      }
      for(byte i=maxim/2;i<2*maxim/3;i++){
        leds[maxim+i].g=0;
        leds[maxim+i].r=255-changeFactor*i;
        leds[maxim+i].b=255;
        
        leds[maxim-i].g=0;
        leds[maxim-i].r=255-changeFactor*i;
        leds[maxim-i].b=255;
      }
      for(byte i=2*maxim/3;i<5*maxim/6;i++){
        leds[maxim+i].g=changeFactor*i;
        leds[maxim+i].r=0;
        leds[maxim+i].b=255;
        
        leds[maxim-i].g=changeFactor*i;
        leds[maxim-i].r=0;
        leds[maxim-i].b=255;
      }
      for(byte i=5*maxim/6;i<maxim;i++){
        leds[maxim+i].g=255;
        leds[maxim+i].r=0;
        leds[maxim+i].b=255-changeFactor*i;
        
        leds[maxim-i].g=255;
        leds[maxim-i].r=0;
        leds[maxim-i].b=255-changeFactor*i;
      }
      delay(10000);
    }
};
#endif
