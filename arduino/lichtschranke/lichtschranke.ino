
// constants won't change. Used here to set a pin number :
const int irLedPin =  2;
const int photoTranseDigitalIn = 3;

int interuptCounter = 0;
int irState = 0;
int lastIrState = 0;
int states[500];
int i = 0;

void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  pinMode(irLedPin, OUTPUT);
  pinMode(photoTranseDigitalIn, INPUT);
  digitalWrite(irLedPin, HIGH);
  delay(50);
}

void loop() {
  int currentIrState = digitalRead(photoTranseDigitalIn);
  
  if (currentIrState != lastIrState) {
    if (currentIrState == HIGH) {
      interuptCounter++;
      Serial.print("number of interupts: ");
      Serial.println(interuptCounter);
    }
  }

  lastIrState = currentIrState;
  
   if (interuptCounter > 0 && interuptCounter % 3 == 0) {
    Serial.println("");
    Serial.println("********************");
    Serial.println("** 3x interrupted **");
    Serial.println("********************");
    interuptCounter = 0;
  }
}

