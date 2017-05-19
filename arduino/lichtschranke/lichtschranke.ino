
// constants won't change. Used here to set a pin number :
const int irLedPin =  2;
const int photoTranseDigitalIn = 3;

int interuptCounter = 0;
int irState = 0;
int lastIrState = 0;
int states[500];
int i = 0;
unsigned long start, finished, elapsed, rpm;

void setup() {
  // set the digital pin as output:
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
    rpm = 60000000/elapsed;
    // Serial.print("Speed: ");
    Serial.println(String(rpm) + ":" + String(elapsed));
    //Serial.write((uint32_t*) data, sizeof(data));
    interuptCounter = 0;
  }
}

