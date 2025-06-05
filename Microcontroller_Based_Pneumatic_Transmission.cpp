//Pin Configuration
#define CLUTCH_PIN        7   // Output to clutch solenoid/actuator
#define UPSHIFT_PIN       5   // Output to upshift solenoid/actuator
#define DOWNSHIFT_PIN     6   // Output to downshift solenoid/actuator

#define UPSHIFT_BUTTON    8   // Input from upshift paddle button
#define DOWNSHIFT_BUTTON  9   // Input from downshift paddle button

//Timing Configuration (in milliseconds)
#define CLUTCH_PRE_DELAY   200
#define GEAR_SHIFT_TIME    150
#define CLUTCH_POST_DELAY  100

void setup() {
  pinMode(CLUTCH_PIN, OUTPUT);
  pinMode(UPSHIFT_PIN, OUTPUT);
  pinMode(DOWNSHIFT_PIN, OUTPUT);

  pinMode(UPSHIFT_BUTTON, INPUT_PULLUP);
  pinMode(DOWNSHIFT_BUTTON, INPUT_PULLUP);

  digitalWrite(CLUTCH_PIN, LOW);
  digitalWrite(UPSHIFT_PIN, LOW);
  digitalWrite(DOWNSHIFT_PIN, LOW);
}

void loop() {
  if (digitalRead(UPSHIFT_BUTTON) == LOW) {
    performShift(UPSHIFT_PIN);
    delay(300); // Debounce delay
  }

  if (digitalRead(DOWNSHIFT_BUTTON) == LOW) {
    performShift(DOWNSHIFT_PIN);
    delay(300); // Debounce delay
  }
}

void performShift(int gearPin) {
  activateClutch();
  delay(CLUTCH_PRE_DELAY);

  digitalWrite(gearPin, HIGH);
  delay(GEAR_SHIFT_TIME);
  digitalWrite(gearPin, LOW);

  delay(CLUTCH_POST_DELAY);
  releaseClutch();
}

void activateClutch() {
  digitalWrite(CLUTCH_PIN, HIGH);
}

void releaseClutch() {
  digitalWrite(CLUTCH_PIN, LOW);
}
