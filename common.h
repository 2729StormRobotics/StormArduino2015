#ifndef COMMON_H
#define COMMON_H
//what every mode needs to function
#include "Mode.h"
#include <Ethernet.h>
#include "FastLED.h"
//needs to be a subclass of Mode
//needs to have the FastLED library
#define NUM_LEDS 270
#define DATA_PIN 8
//number of LEDs and the pin on the arduino used to communicate with LEDS.
CRGB leds[NUM_LEDS];
//the actual LEDS themselves. Not sure, but this variable might have to be called leds.
//each led array member has three values: a red, blue, and green value
//you assign them with {CRGB variable}.r, {CRGB variable}.b, {CRGB variable}.g
//where {CRGB variable} is some CRGB variable, not necessarily the leds variable. for an example
//where it's not LEDs, take a look at the Morse.h start() method.
CRGB ORANGE  = 0xFF1000;
CRGB YELLOW  = 0xFF6400;
CRGB OFF=0x000000;
byte Alliance;
boolean teleOpModeCheck=false;
EthernetServer arduino = EthernetServer(1024);
EthernetClient roborio=arduino.available();
//OFF turns them off (for reference, 0x000000 is black)
//hex codes can also be used to specify color. preface the hex code with 0x and all is good

//SOME TERMS:
//particle: a single "moving" LED, where the led is quickly turned on, and then the next one is turned on, and then the first is turned off.
//null particle: a "particle" that is essentially an off LED that moves down a line of typically all on leds and turns them off
#endif
