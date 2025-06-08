// Transmission Pin Configuration
#define CLUTCH_PIN        7
#define UPSHIFT_PIN       5
#define DOWNSHIFT_PIN     6

#define UPSHIFT_BUTTON    8
#define DOWNSHIFT_BUTTON  9

// Aero Pin Configuration
#define AERO_UP_PIN       12
#define AERO_UP_EXTRA_PIN 11
#define AERO_UP_SWITCH    10

// Timing Configuration (in milliseconds)
#define CLUTCH_PRE_DELAY   200
#define GEAR_SHIFT_TIME    150
#define CLUTCH_POST_DELAY  100

// State tracking
bool shifting = false;
unsigned long shiftStartTime = 0;
int currentShiftPin = -1;
int shiftStage = 0;

void setup() {
  // Transmission outputs
  pinMode(CLUTCH_PIN, OUTPUT);
  pinMode(UPSHIFT_PIN, OUTPUT);
  pinMode(DOWNSHIFT_PIN, OUTPUT);

  // Transmission inputs
  pinMode(UPSHIFT_BUTTON, INPUT_PULLUP);
  pinMode(DOWNSHIFT_BUTTON, INPUT_PULLUP);

  // Aero
  pinMode(AERO_UP_PIN, OUTPUT);
  pinMode(AERO_UP_EXTRA_PIN, OUTPUT);
  pinMode(AERO_UP_SWITCH, INPUT_PULLUP);

  // Set all outputs LOW initially
  digitalWrite(CLUTCH_PIN, LOW);
  digitalWrite(UPSHIFT_PIN, LOW);
  digitalWrite(DOWNSHIFT_PIN, LOW);
  digitalWrite(AERO_UP_PIN, LOW);
  digitalWrite(AERO_UP_EXTRA_PIN, LOW);
}

void loop() {
  unsigned long currentTime = millis();

  // Aero Control
  if (digitalRead(AERO_UP_SWITCH) == LOW) {
    digitalWrite(AERO_UP_PIN, HIGH);
    digitalWrite(AERO_UP_EXTRA_PIN, HIGH);
  } else {
    digitalWrite(AERO_UP_PIN, LOW);
    digitalWrite(AERO_UP_EXTRA_PIN, LOW);
  }

  // Shift Trigger
  if (!shifting) {
    if (digitalRead(UPSHIFT_BUTTON) == LOW) {
      startShift(UPSHIFT_PIN);
    } else if (digitalRead(DOWNSHIFT_BUTTON) == LOW) {
      startShift(DOWNSHIFT_PIN);
    }
  }

  // Gear Shift Sequence (Non-blocking)
  if (shifting) {
    if (shiftStage == 0 && currentTime - shiftStartTime >= 0) {
      digitalWrite(CLUTCH_PIN, HIGH); // Activate clutch
      shiftStartTime = currentTime;
      shiftStage = 1;
    }

    else if (shiftStage == 1 && currentTime - shiftStartTime >= CLUTCH_PRE_DELAY) {
      digitalWrite(currentShiftPin, HIGH); // Activate gear
      shiftStartTime = currentTime;
      shiftStage = 2;
    }

    else if (shiftStage == 2 && currentTime - shiftStartTime >= GEAR_SHIFT_TIME) {
      digitalWrite(currentShiftPin, LOW); // Deactivate gear
      shiftStartTime = currentTime;
      shiftStage = 3;
    }

    else if (shiftStage == 3 && currentTime - shiftStartTime >= CLUTCH_POST_DELAY) {
      digitalWrite(CLUTCH_PIN, LOW); // Release clutch
      shifting = false; // Done
      shiftStage = 0;
      currentShiftPin = -1;
    }
  }
}

void startShift(int gearPin) {
  shifting = true;
  shiftStartTime = millis();
  currentShiftPin = gearPin;
  shiftStage = 0;
}