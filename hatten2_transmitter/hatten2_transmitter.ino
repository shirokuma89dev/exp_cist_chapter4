int outpin = 3;
int data_length = 7;
int base = 4;    // n進数の定義
// int base = 3
int value[] = {0, 2, 1, 0, 3, 1, 2};
// int data[] = {0, 1, 2, 1, 0, 3, 1}
int threshold = 0;
int dly = 100;  // 100, 20, 5
int dly2 = 500; 

void data2Bright(int *value, int base, int *bright) {
  int step = (255 - threshold) / base;

  for (int i = 0; i < data_length; i++) {
    bright[i] = threshold + value[i] * step;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);
}

void loop() {
  analogWrite(outpin, 0); 
  Serial.println("0 (Start)");
  delay(dly);

  int bright[data_length] = {0};
  data2Bright(value, base, bright);

  for (int i = 0; i < data_length; i++) {
    analogWrite(outpin, bright[i]);
    Serial.println(value[i]);
    delay(dly);
  }
  analogWrite(outpin, 255);
  Serial.println("0 (End)");
  delay(dly2);
}
