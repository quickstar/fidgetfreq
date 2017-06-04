// constants won't change. Used here to set a pin number :
const int irLedPin =  2;
const int photoTranseDigitalIn = 3;

int interuptCounter = 0;
int irState = 0;
int lastIrState = 0;
int states[500];
unsigned long start, finished, elapsed, oldElapsed;
float freq, oldFreq, diff, estimated;

void setup() {
  // set the digital pin as output:
  oldElapsed = 0;
  elapsed = 0;
  
  Serial.begin(9600);
  pinMode(irLedPin, OUTPUT);
  pinMode(photoTranseDigitalIn, INPUT);
  digitalWrite(irLedPin, HIGH);
  delay(50);
}

void loop() {
  if (interuptCounter == 0) {
    start = micros();
  }
  
  int currentIrState = digitalRead(photoTranseDigitalIn);
  if (currentIrState != lastIrState) {
    if (currentIrState == HIGH) {
      interuptCounter++;
    }
  }

  lastIrState = currentIrState;
   if (interuptCounter > 0 && interuptCounter % 3 == 0) {
    finished = micros();
    elapsed = finished - start;
    Serial.println(elapsed);

/*
    freq = getFrequency(elapsed);
    if (oldFreq > freq) {
        diff = oldFreq - freq;
        estimated = (float)((float)freq / (float)diff);


        // Serial.println(estimated);
        // Serial.println(diff);
         Serial.println("freq: " + String(freq) + " diff: " + String(diff) +  " estimated: " + String(estimated));
    }
    oldFreq = freq;
    */

    
    // if (elapsed > oldElapsed) {
      // diff = elapsed - oldElapsed;
//       estimated = (elapsed^2 / diff);
      
      // Serial.println("Elapsed: " + String(elapsed) + "; oldElapsed: " + String(oldElapsed) + "; diff: " + String(diff) + " estimated: " + String(estimated));
   //  }
    // oldElapsed = elapsed;

    
    
    interuptCounter = 0;
  }

  
}

float getFrequency(long elapsedInMicros) {
  return (float)(1/((float)elapsedInMicros/1000000));
}

String getRpm(long elapsedInMicros) {
  return String((float)60000000/elapsed);
}

