#include "Arduino.h"
#include "Rotation.h"

const int interruptCount = 3;
unsigned long _interrupts[interruptCount];
int _interruptCounter;

Rotation::Rotation() {
	_interruptCounter = 0;
}

Rotation::~Rotation() {
	delete[] _interrupts;
}

void Rotation::addInterrupt(unsigned long interruptTime) {
  if (_interruptCounter > interruptCount - 1) {
    _interruptCounter = 0;
  }

  _interrupts[_interruptCounter] = interruptTime;
  _interruptCounter++;
}

void Rotation::Reset() {
	_interruptCounter = 0;
}

String Rotation::toString() {
	String output;
	String delimiter = ",";
	for (int i = 0; i < interruptCount; i++) {
	 	output += String(_interrupts[i]) + (i == interruptCount - 1 ? "" : delimiter);
	}
	return output;
}

