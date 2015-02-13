#include "FastLED.h"
#include <Ethernet.h>
#include <SPI.h>
//basic stuff^^^^^
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
#include "Mode.h"
//our stuff ^^^^^^^

enum mode{
  disabled_,
  randomMode_,
  blackMagMode_,
  morseMode_  
};

EthernetClient roborio;
EthernetServer server(6969);
byte mac[]={0xab,0xcd,0xef,0x12,0x34,0x56};
IPAddress ip(10,27,29,100);
//byte ipAddress[] ={10,27,29,2};

Disabled* disabled =new Disabled();
TeleOp* TeleOpMode =new TeleOp();
Autonomous* AutoMode =new Autonomous();
randomMode* randoM = new randomMode(); //don't let this fool you.
Morse* morse = new Morse();            //Constructors don't real
BlackMagic* blackMagic=new BlackMagic();       //Only pointers do
DoubleStack* doubleStack=new DoubleStack();
RainbowDanceParty* RDP=new RainbowDanceParty();
TwoSpeedStack* TwoXStack = new TwoSpeedStack();

//Here there be pointers (hence the cute little *)  
  
Mode* curMode=blackMagic; //curMode get hype
//We use this because having a giant switch case every time
//we want to talk to our current mode is stupid as hell
 void setup(){
     Ethernet.begin(mac,ip);
     FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds,NUM_LEDS);
     FastLED.clear();//makes sure nothing is on for no reason, because that happens sometimes
    
     FastLED.show();//not sure why, and don't feel like finding out why
     Serial.begin(9600);
     
}
void loop(){
     if(!roborio.connected()){
       roborio=server.available();
     }
     modeRead();  
     curMode->start(); //start whatever mode is selected
     }    
void modeRead(){
   if(roborio.available()){
     //roborio.connect();
     modeChange(roborio.read());
   }
}
 void modeChange(byte mode){
      switch(mode){
        case 0:    curMode=disabled;
                   break;
        case 1:    curMode=TeleOpMode;
                   break;
        case 2:    curMode=AutoMode;
                   break;
        case 3:    curMode=morse;
                   break;
        case 4:    curMode=blackMagic;
                   break;
        case 5:    curMode=doubleStack;
                   break;
        case 6:    curMode=TwoXStack;
                   break;
        case 7:    curMode=RDP;
                   break;
        case 8:    curMode=randoM;
                   break;
      }
   }
 
