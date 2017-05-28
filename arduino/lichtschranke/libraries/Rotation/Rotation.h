#ifndef Rotation_h
#define Rotation_h

#include "Arduino.h"

class Rotation {
  public:
    Rotation();
    void addInterrupt(long interruptTime);
  private:
    long _interrupts[3];
    int _interruptCounter;
};

#endif
