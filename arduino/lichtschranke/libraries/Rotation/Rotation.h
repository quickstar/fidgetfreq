#ifndef Rotation_h
#define Rotation_h

#include "Arduino.h"

class Rotation {
  public:
    Rotation();
    ~Rotation(); // destructor
    void addInterrupt(unsigned long interruptTime);
    void Reset();
    String toString();
  private:
    unsigned long _interrupts[3];
    int _interruptCounter;
};

#endif
