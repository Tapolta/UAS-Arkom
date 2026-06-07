const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int pinReset = 10;
const int pinUpDown = 11;
const int pinPot = A0;

uint8_t counterRegister = 0; 

bool isUpDirection = true;
unsigned long lastTickTime = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(pinReset, INPUT_PULLUP);  
  pinMode(pinUpDown, INPUT_PULLUP); 
  
  Serial.begin(9600); 
}

void loop() {
  if (digitalRead(pinReset) == LOW) {
    counterRegister = 0; 
    updateLEDOutputs();
    delay(200);
    return;
  }

  if (digitalRead(pinUpDown) == LOW) {
    isUpDirection = !isUpDirection;
    delay(200);
  }

  int potValue = analogRead(pinPot);
  unsigned long tickInterval = map(potValue, 0, 1023, 100, 2000);

  unsigned long currentMillis = millis();
  if (currentMillis - lastTickTime >= tickInterval) {
    lastTickTime = currentMillis;

    if (isUpDirection) {
      counterRegister++; 
    } else {
      counterRegister--; 
    }

    updateLEDOutputs();
    
    Serial.print("Register Value: ");
    Serial.print(counterRegister);
    Serial.print(" | Direction: ");
    Serial.print(isUpDirection ? "UP" : "DOWN");
    Serial.print(" | Tick Interval: ");
    Serial.print(tickInterval);
    Serial.println(" ms");
  }
}

void updateLEDOutputs() {
  for (int i = 0; i < 8; i++) {
    int bitValue = (counterRegister >> i) & 1;
    digitalWrite(ledPins[i], bitValue);
  }
}