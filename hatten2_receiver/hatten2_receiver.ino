//受信用 便番号 -> A1
int dly = 100;
int stat;
int data_length = 7;
int base = 3;
int data[7];
int thresholds[4] = {0, 90, 160, 220};
int offset = 80;


void setup() { 
  Serial.begin(9600);

  double step = 120 / base;
  /*
  for (int i = 0; i < base+1; i++) {
    thresholds[i] = (int)(offset + step * i);
  }*/
}

void loop() {
  int rawValue = analogRead(1);
  stat = rawValue < thresholds[1] ? 0 : -1; //スタートビットが0か判別できればいい
  Serial.println(stat);
  delay(dly);
//  Serial.println(rawValue);
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
    for (int i = 0; i < data_length; i++) {
      Serial.print(data[i]);
    }
    Serial.println();
  }

}
