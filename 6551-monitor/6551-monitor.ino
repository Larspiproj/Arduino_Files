//const char ADDR[] = {22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52};
const char DATAR[] = {39, 41, 43, 45, 47, 49, 51, 53};
const char DATAF[] = {38, 40, 42, 44, 46, 48, 50, 52};
#define CLOCKR 2
#define CLOCKF 21
#define READ_WRITE 3

void setup() {
  for (int n = 0; n < 8; n++) {
    pinMode(DATAR[n], INPUT);
  }
  for (int n = 0; n < 8; n++) {
      pinMode(DATAF[n], INPUT);
    }
    pinMode(CLOCKR, INPUT);
    pinMode(CLOCKF, INPUT);
    pinMode(READ_WRITE, INPUT);

    attachInterrupt(digitalPinToInterrupt(CLOCKR), onClockR, RISING);
    attachInterrupt(digitalPinToInterrupt(CLOCKF), onClockF, FALLING);

    Serial.begin(57600);
    Serial.println("Rising Edge first");
}

//int step = 1;
void onClockR() {
  char output[7];

  unsigned int dataR = 0;
  //Serial.print(step);
  //Serial.print("  ");
  //step++;
  //Serial.print("Rising edge:  ");
  //sprintf(output, "  %c", digitalRead(READ_WRITE) ? 'r' : 'w');
  //Serial.println(output);
  for (int n = 0; n < 8; n++) {
    int bit = digitalRead(DATAR[n]) ? 1 : 0;  
    Serial.print(bit);
    Serial.print(" ");
    dataR = (dataR << 1) + bit;

  }
  //Serial.println();
  sprintf(output, "  %02x %c", dataR, digitalRead(READ_WRITE) ? 'r' : 'w');
  Serial.println(output);
}

  //Serial.print("  ");

void onClockF() {
  char output[7];

  unsigned int dataF = 0;
  //Serial.print("Falling edge: ");
  //sprintf(output, "  %c", digitalRead(READ_WRITE) ? 'r' : 'w');
  //Serial.println(output);
  for (int n = 0; n < 8; n++) {
    int bit = digitalRead(DATAF[n]) ? 1 : 0;  
    Serial.print(bit);
    Serial.print(" ");
    dataF = (dataF << 1) + bit;
  }

  sprintf(output, "  %02x %c", dataF, digitalRead(READ_WRITE) ? 'r' : 'w');
  Serial.println(output);
  Serial.println();

  //Serial.print("  ");

  //sprintf(output, "  %02x %c %02x", dataF, digitalRead(READ_WRITE) ? 'r' : 'w', dataR);
  //Serial.println(output);

  }

void loop() {
}

