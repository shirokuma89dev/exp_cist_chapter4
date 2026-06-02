//受信用 便番号 -> A1
int dly = 100;
int stat;
int data_length = 7;
int base = 4;
int data[7];
int thresholds[base+1] = {0};

void setup() { 
  Serial.begin(9600);

  double step = 255 / base;
  for (int i = 0; i < base+1; i) {
    thresholds[i] = (int)(step * i);
  }
}

void loop() {
  int rawValue = analogRead(1);
  stat = rawValue < thresholds[0] ? 0 : -1; //スタートビットが0か判別できればいい
  Serial.println(stat);
  delay(dly);

  if (stat == 0) {
    for (int i = 0; i < data_length; i++) {
      rawValue = analogRead(1);

      for (int j = 0; j < base; j++) {
        if (thresholds[j] < rawValue && rawValue < thresholds[j+1]){
          data[i] = j;
          break;
        }
      }
      delay(dly);
    }
    for (int i = data_length - 1; i >= 0; i--) {
      Serial.print(data[i]);
    }
    Serial.println();
  }

}