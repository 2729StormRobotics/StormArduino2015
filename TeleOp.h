#ifndef TELEOP_H
#define TELEOP_H

class TeleOp:public Mode{
  public:
    byte allianceColor;
    double stringPot;
     void start(){
       CRGB color;
      allianceColor=getAlliance();
      while(teleOpModeCheck){
        for(int i=5;i<NUM_LEDS/2;i++){
          leds[i].r=255;
          leds[i].g=255;
          leds[i].b=255;
          switch(allianceColor){
            case 1: {
              leds[i-1]=color;
            }
          }
        }
      }
    }
    void blueAlliance(){
      for(int i=6;i<NUM_LEDS/2;i++){
        leds[i-1].r=204;
        leds[i-1].g=204;
        leds[i-1].b=255;
        leds[i-2].r=153;
        leds[i-2].g=153;
        leds[i-2].b=255;
        leds[i-3].r=102;
        leds[i-3].g=102;
        leds[i-3].b=255;
        leds[i-4].r=51;
        leds[i-4].g=51;
        leds[i-4].b=255;
        leds[i-5].r=0;
        leds[i-5].g=0;
        leds[i-5].b=255;
        
        leds[NUM_LEDS-i+1].r=204;
        leds[NUM_LEDS-i+1].g=204;
        leds[NUM_LEDS-i+1].b=255;
        leds[NUM_LEDS-i+2].r=153;
        leds[NUM_LEDS-i+2].g=153;
        leds[NUM_LEDS-i+2].b=255;
        leds[NUM_LEDS-i+3].r=102;
        leds[NUM_LEDS-i+3].g=102;
        leds[NUM_LEDS-i+3].b=255;
        leds[NUM_LEDS-i+4].r=51;
        leds[NUM_LEDS-i+4].g=51;
        leds[NUM_LEDS-i+4].b=255;
        leds[NUM_LEDS-i+5].r=0;
        leds[NUM_LEDS-i+5].g=0;
        leds[NUM_LEDS-i+5].b=255;
      }
    }
    void getStringPot(){
      roborio.read();
    }
    byte getAlliance(){
      roborio.read();
    }
};


#endif
