#include "FastLED.h"
#include <Ethernet.h>
#include <SPI.h>
//basic stuff^^^^^
#include "common.h"
#include "randomMode.h"
#include "Morse.h"
#include "BlackMagic.h"
#include "DoubleStack.h"
#include "RainbowDanceParty.h"
#include "TwoSpeedStack.h"
#include "Mode.h"
//our stuff ^^^^^^^

enum mode{
  disabled_,
  randomMode_,
  blackMagMode_,
  morseMode_  
};

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
     FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds,NUM_LEDS);
     FastLED.clear();//makes sure nothing is on for no reason, because that happens sometimes.
     FastLED.show();//not sure why, and don't feel like finding out why
     Serial.begin(9600);
     
}
void loop(){
     curMode->start(); //start whatever mode is selected
     }     
