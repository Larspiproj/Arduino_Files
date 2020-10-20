const char CHANNELS[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
#define CLOCK 2

int n, bit;
int step = 1;

void setup() {
  for (n = 0; n < 11; n++) {
    pinMode(CHANNELS[n], INPUT);  
  }
  pinMode(CLOCK, INPUT);

  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);

  Serial.begin(57600);
}

void onClock() {
  char output[15];
  unsigned int channel = 0;
  Serial.println(step);
  step++;
  for (n = 0; n < 11; n++) {
    bit = digitalRead(CHANNELS[n]);// ? 1 : 0;
    Serial.print(bit);
    channel = (channel << 1) + bit;
  }
  sprintf(output, "  %04x", channel);
  Serial.println(output);
}

void loop() {
}

