#ifndef MODE_H
#define MODE_H

#include "common.h"
//basically this makes it so I can have one variable that just is able to handle all modes that will be used.
class Mode{
  public:
    virtual void start(); //so when the mode is called it looks for the "start" method if this is called from the .ino (StormArduino2015.ino)
};

#endif
