#ifndef TELEOP_H
#define TELEOP_H

class TeleOp:public Mode{
  public:
    CRGB color;
    byte allianceColor;
    double stringPot;
     void start(){
       
      allianceColor=getAlliance();
      while(teleOpModeCheck){
        if(getClamp()){
          stringPot=getStringPot();
          stringPot=stringPot/0.90;
          setColor();
          
        }else{
            switch(allianceColor){
            case 0: blueAlliance();
                    break;
            case 1: redAlliance();
                    break;
            case 2: invalid();
                    break;
            case 3: what();
                    break;
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
        FastLED.show();
      }
    }
        void redAlliance(){
      for(int i=6;i<NUM_LEDS/2;i++){
        leds[i-1].r=204;
        leds[i-1].g=255;
        leds[i-1].b=204;
        leds[i-2].r=153;
        leds[i-2].g=255;
        leds[i-2].b=153;
        leds[i-3].r=102;
        leds[i-3].g=255;
        leds[i-3].b=102;
        leds[i-4].r=51;
        leds[i-4].g=255;
        leds[i-4].b=51;
        leds[i-5].r=0;
        leds[i-5].g=255;
        leds[i-5].b=0;
        
        leds[NUM_LEDS-i+1].r=204;
        leds[NUM_LEDS-i+1].g=255;
        leds[NUM_LEDS-i+1].b=204;
        leds[NUM_LEDS-i+2].r=153;
        leds[NUM_LEDS-i+2].g=255;
        leds[NUM_LEDS-i+2].b=153;
        leds[NUM_LEDS-i+3].r=102;
        leds[NUM_LEDS-i+3].g=255;
        leds[NUM_LEDS-i+3].b=102;
        leds[NUM_LEDS-i+4].r=51;
        leds[NUM_LEDS-i+4].g=255;
        leds[NUM_LEDS-i+4].b=51;
        leds[NUM_LEDS-i+5].r=0;
        leds[NUM_LEDS-i+5].g=255;
        leds[NUM_LEDS-i+5].b=0;
        FastLED.show();
      }
    }
    void invalid(){
       for(int i=6;i<NUM_LEDS/2;i++){
        leds[i-1].r=255;
        leds[i-1].g=204;
        leds[i-1].b=204;
        leds[i-2].r=255;
        leds[i-2].g=153;
        leds[i-2].b=153;
        leds[i-3].r=255;
        leds[i-3].g=102;
        leds[i-3].b=102;
        leds[i-4].r=255;
        leds[i-4].g=51;
        leds[i-4].b=51;
        leds[i-5].r=255;
        leds[i-5].g=0;
        leds[i-5].b=0;
        
        leds[NUM_LEDS-i+1].r=255;
        leds[NUM_LEDS-i+1].g=204;
        leds[NUM_LEDS-i+1].b=204;
        leds[NUM_LEDS-i+2].r=255;
        leds[NUM_LEDS-i+2].g=153;
        leds[NUM_LEDS-i+2].b=153;
        leds[NUM_LEDS-i+3].r=255;
        leds[NUM_LEDS-i+3].g=102;
        leds[NUM_LEDS-i+3].b=102;
        leds[NUM_LEDS-i+4].r=255;
        leds[NUM_LEDS-i+4].g=51;
        leds[NUM_LEDS-i+4].b=51;
        leds[NUM_LEDS-i+5].r=255;
        leds[NUM_LEDS-i+5].g=0;
        leds[NUM_LEDS-i+5].b=0;
        FastLED.show();
      }
    }
    void what(){
      for(int i = 0;i<NUM_LEDS;i++){
        leds[i].r=255;
        leds[i].g=0;
        leds[i].b=0;
      }
      FastLED.show();
      delay(250);
      for(int i = 0;i<NUM_LEDS;i++){
        leds[i].r=0;
        leds[i].g=0;
        leds[i].b=0;
      }
      FastLED.show();
    }
    void stringPotLights(double potValue){
      for(int i=0;i<NUM_LEDS*potValue;i++){
        leds[i]=color;
      }
      FastLED.show();
    }
    void setColor(){
      switch(getAlliance()){
        case 0:{color.r=0,
                color.g=0,
                color.b=255;
                break;
        }
        case 1:{color.r=0,
                color.g=255,
                color.b=0;
                break;
        }
        case 2:{color.r=255,
                color.g=0,
                color.b=0;
                break;
        }
        case 3:{color.r=255,
                color.g=255,
                color.b=255;
                break;
        }
      }
    }
    double getStringPot(){
      return (double)roborio.read()/1000.;
    }
    byte getAlliance(){
      return roborio.read();
    }
    boolean getClamp(){
      return roborio.read();
    }
};


#endif
