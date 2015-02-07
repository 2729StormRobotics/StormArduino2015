#ifndef MORSE_H
#define MORSE_H
using namespace std;

#include "common.h"

class Morse: public Mode{
    public:
      void start(){
        char toMake[]="EVAN ALLAN";//input thing to morse up here
        translate(toMake, YELLOW);//goes directly to second to last method.
      }
      void dot(CRGB color){ //This does the dot
        for(int i=0;i<NUM_LEDS;i++){
          leds[i]=color;    //set all of the leds to a certain color
        }
        FastLED.setBrightness(255); //hurt your eyes
        FastLED.show();
        delay(100);   //wait half a second
       FastLED.clear();
       FastLED.show();
        delay(100);
      }
      void dash(CRGB color){ //this does the dash
        for(int i=0;i<NUM_LEDS;i++){
          leds[i]=color;  //set all of the leds to a certain color
        }
        FastLED.setBrightness(255); //make them blinding
        FastLED.show();
        delay(250); //wait for like a quarter of a second with them on
        FastLED.clear(); 
        FastLED.show();  //turn them all off
        delay(100);      //wait a tenth of a second until the next dot/dash
      }
    void translate(char toTrans[],CRGB color){//from the inputed word to the morse, let it be known that this first color is just the initial color of the strip
      //prepare for hardcoding...
      for(int i=0; i<length(toTrans)-1;i++){
        switch(toTrans[i]){                                                        //fairly self explanatory, this is basically just taking in the 
          case 'A': dot(color);dash(color); break;                                 //character and then doing the dot and dash methods above accordingly
          case 'B': dash(color); dot(color); dot(color); dot(color); break;        //for each different character.
          case 'C': dash(color); dot(color); dash(color); dot(color); break;
          case 'D': dash(color); dot(color); dot(color); break;
          case 'E': dot(color); break;
          case 'F': dot(color); dot(color); dash(color); dot(color);break;
          case 'G': dash(color); dash(color); dot(color);break;
          case 'H': dot(color);dot(color);dot(color);dot(color);break;
          case 'I': dot(color);dot(color);break;
          case 'J': dot(color);dash(color); dash(color);dash(color);break;
          case 'K': dash(color);dot(color);dash(color);break;
          case 'L': dot(color); dash(color); dot(color); dot(color);  break;
          case 'M': dash(color); dash(color);   break;
          case 'N': dash(color); dot(color);   break;
          case 'O': dash(color);dash(color);dash(color); break;
          case 'P': dot(color);dash(color);dash(color);dot(color); break;
          case 'Q': dash(color); dash(color); dot(color); dash(color);   break;
          case 'R': dot(color); dash(color); dot(color);   break;
          case 'S': dot(color);dot(color);dot(color);  break;
          case 'T': dash(color);   break;
          case 'U': dot(color);dot(color);dash(color);   break;
          case 'V':dot(color);dot(color);dot(color);dash(color);   break;
          case 'W': dot(color);dash(color);dash(color);  break;
          case 'X': dash(color); dot(color);dot(color);dash(color);   break;                      //this took 30 minutes to hard code
          case 'Y': dash(color); dot(color);dash(color);dash(color);   break;
          case 'Z': dash(color); dash(color);dot(color);dot(color);  break;
          case '.': dot(color); dash(color); dot(color);dash(color); dot(color); dash(color);   break;
          case ',': dash(color); dash(color); dot(color);dot(color);dash(color); dash(color);   break;
          case '?':dot(color);dot(color);dash(color); dash(color);dot(color);dot(color);  break;        //it's essentially useless
          case '!':dot(color);dash(color);dot(color); dash(color); dot(color); dot(color);   break;
          case '0':dash(color);dash(color);dash(color);dash(color);dash(color);  break;
          case '1':dot(color);dash(color);dash(color);dash(color);dash(color);   break;
          case '2': dot(color); dot(color); dash(color);dash(color);dash(color);  break;
          case '3':dot(color); dot(color); dot(color); dash(color); dash(color);  break;
          case '4': dot(color); dot(color); dot(color); dot(color); dash(color);   break;
          case '5': dot(color); dot(color); dot(color); dot(color); dot(color);   break;
          case '6': dash(color); dot(color); dot(color); dot(color); dot(color);   break;
          case '7': dash(color); dash(color); dot(color); dot(color); dot(color);   break;
          case '8': dash(color);dash(color);dash(color); dot(color); dot(color);   break;
          case '9': dash(color);dash(color);dash(color);dash(color);dot(color);   break;
          case ' ': delay(1750);break; //length of 7 dashes waited (morse standard)
        }
        if(toTrans[i]!=' '){
          delay(600);//if it isn't a space wait for the period of three dots (morse standard)
        }else{
          color.r=random(256),  //reassigns the color of the leds to some random color
          color.g=random(256),  //because it helps people visually discern between two words.
          color.b=random(256);
        }
        }
      delay(1750);
    }
    int length(char arr[]){ //because C++ loves to let you know nothing about the array that you have.
      int acc=0;
      while(arr[acc]!='\0'){//just keep checking every single array member until it finds the null character
        acc++;              //when it does it leaves, counting up the length of the array as it goes
      }
      return acc;          //returns that length
    }                      //not guaranteed to work all the time but it gets the job done
}; 
#endif
