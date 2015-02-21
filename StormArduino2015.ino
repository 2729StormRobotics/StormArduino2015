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
byte mac[]={0x0a,0x1b,0x2c,0x3d,0x4e,0x5f};
IPAddress ip(10,27,29,100);
IPAddress gateway(10,27,29,1);
IPAddress subnet(255,0,0,0);
IPAddress ipRobo(10,27,29,2);
byte ipAddress[] ={10,27,29,2};

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
  
Mode* curMode=blackMagic; //curMode get hype
//We use this because having a giant switch case every time
//we want to talk to our current mode is stupid as hell
 void setup(){
     Ethernet.begin(mac,ip,gateway,subnet);
          Serial.begin(9600);
    // roborio.begin();
     while(!roborio){
       roborio.connect(ipRobo,1024);
       Serial.println("Connecting to Ethernet Client...");
       Serial.println();
       Serial.print("Status of connection = ");
       Serial.println(roborio.connect(ipRobo,1024));
       Serial.print("IP = ");
       Serial.println(Ethernet.localIP());
       Serial.println();
       Serial.print("Mac Address: ");
       for(int i=0;i<5;i++){
         Serial.print(mac[i]);
         Serial.print(".");
       }
       Serial.println();
       delay(2000);
         }//wait until the client is ready
        Serial.println("Connected!");
     FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds,NUM_LEDS);
     FastLED.clear();//makes sure nothing is on for no reason, because that happens sometimes
    
     FastLED.show();//this is due to previous modes already being loaded up on the Arduino before startup.
     
}
void loop(){
     if(!roborio.connected()){
       roborio.stop();
     //  roborio=server.available();
       Serial.println("Not Connected...");
       if(roborio.connect(ipAddress,1024)){
         Serial.println("Connected!");
         Serial.println("mode will now change properly");
       }else{
         Serial.print("Connection failure. Error Code: ");
         Serial.println(roborio.connect(ipAddress, 1024));
       }
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
       curMode=modeChanger[mode];
      }
 
