#include "FastLED.h"
#include <Ethernet.h>
#include <SPI.h>
#include "RainbowDanceParty.h"

RainbowDanceParty* RDP = new RainbowDanceParty();


void setup(){
       FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds,NUM_LEDS);
}
void loop(){
  RDP->start();
}
