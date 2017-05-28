#include "Arduino.h"
#include "Rotation.h"

long _interrupts[3];
int _interruptCounter;

Rotation::Rotation() {
  _interruptCounter = 0;
}

void Rotation::addInterrupt(long interruptTime) {
  if (_interruptCounter > 2) {
    _interruptCounter = 0;
  }
  
  _interrupts[_interruptCounter] = interruptTime;
  _interruptCounter++;
}

