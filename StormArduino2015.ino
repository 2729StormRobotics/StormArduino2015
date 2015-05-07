#include "FastLED.h"
#include <Ethernet.h>
#include <SPI.h>
//basic stuff^^^^^
#include "Mode.h"
#include "Disabled.h"
#include "common.h"
#include "randomMode.h"
#include "Morse.h"
#include "BlackMagic.h"
#include "DoubleStack.h"
#include "RainbowDanceParty.h"
#include "TwoSpeedStack.h"
#include "Autonomous.h"
#include "TeleOp.h"
//our stuff ^^^^^^^

/*
*VERY IMPORTANT NOTE: for some reason on this chipset of LEDs
*the red and the green are swapped, so all calls of leds[#].g
*are for the red and all of the calls of leds[#].r are for green
*/ 

byte mac[]={0x00,0xAA,0xBB,0xCC,0xDD,0xEE};
IPAddress ip(10,27,29,100);
IPAddress gateway(10,27,29,1);
IPAddress subnet(255,0,0,0);
IPAddress ipRobo(10,27,29,2);

Disabled* disabled =new Disabled();
TeleOp* TeleOpMode =new TeleOp();
Autonomous* AutoMode =new Autonomous();
randomMode* randoM = new randomMode(); //don't let this fool you.
Morse* morse = new Morse();            //Constructors don't real
BlackMagic* blackMagic=new BlackMagic();       //Only pointers do
DoubleStack* doubleStack=new DoubleStack();
RainbowDanceParty* RDP=new RainbowDanceParty();
TwoSpeedStack* TwoXStack = new TwoSpeedStack();

Mode* modeChanger[]={disabled, TeleOpMode, AutoMode, randoM, morse, blackMagic,doubleStack,RDP,TwoXStack};
//Here there be pointers (hence the cute little *)  
  
Mode* curMode = RDP;//curMode get hype
//We use this because having a giant switch case every time
//we want to talk to our current mode is stupid as hell
 void setup(){
//     Serial.begin(9600);
       Ethernet.begin(mac,ip);
       arduino.begin();
      delay(1000);
       roborio=arduino.available();
     FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds,NUM_LEDS);
     FastLED.clear();//makes sure nothing is on for no reason, because that happens sometimes
    
     FastLED.show();//this is due to previous modes already being loaded up on the Arduino before startup.
     
}
void loop(){
    roborio=arduino.available();
    if(!roborio){
       roborio=arduino.available();

     }else{
       modeRead(); 
    
     }
     curMode->start();
}    
void modeRead(){
   if(roborio.available()){
     modeChange(roborio.read());
   }
}
 void modeChange(byte mode){
       curMode=modeChanger[mode];
       if(curMode==TeleOpMode){
         teleOpModeCheck=true;
       }else teleOpModeCheck=false;
 }
 
