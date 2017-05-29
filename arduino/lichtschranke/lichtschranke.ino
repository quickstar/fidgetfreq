#include <Rotation.h>

// constants won't change. Used here to set a pin number :
const int irLedPin =  2;
const int photoTranseDigitalIn = 3;

int interuptCounter = 0;
int lastIrState = 0;
int states[500];
int startSet = 0;
unsigned long start, finished, elapsed;

Rotation* rotation;


void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  pinMode(irLedPin, OUTPUT);
  pinMode(photoTranseDigitalIn, INPUT);
  digitalWrite(irLedPin, HIGH);
  delay(50);
  rotation = new Rotation();
}

void loop() {
  if (interuptCounter == 0 && startSet == 0) {
    start = micros();
    startSet = 1;
    rotation->Reset();
  }

  int currentIrState = digitalRead(photoTranseDigitalIn);
  if (currentIrState != lastIrState) {
    
    if (currentIrState == HIGH) {
      finished = micros();
      elapsed = finished - start;
      start = micros();
      rotation->addInterrupt(elapsed);
      interuptCounter++;
    }
  }

  lastIrState = currentIrState;
   if (interuptCounter > 0 && interuptCounter % 3 == 0) {
    Serial.println(rotation->toString());
    //Serial.write((uint32_t*) data, sizeof(data));
    interuptCounter = 0;
    startSet = 0;
  }
}

String getFrequency(long elapsedInMicros) {
  return String((1/((float)elapsedInMicros/1000000)));
}

String getRpm(long elapsedInMicros) {
  return String((float)60000000/elapsed);
}

