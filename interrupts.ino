const byte interruptPin = 2;

void setup() {
  pinMode(interruptPin, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(interruptPin), print, RISING);
  Serial.begin(57600);
}

void print() {
  Serial.println("RISING");  
}
void loop() {

}

