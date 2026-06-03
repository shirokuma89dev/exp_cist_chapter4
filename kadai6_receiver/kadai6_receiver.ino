// 受信用 ピン番号 -> A1
int dly = 100; // 各ビットの受信間隔 (送信側と共通, 100, 20, 5)
int stat;
int data_length = 7;
int data[7];  // 7bit データ
int threshold = 300;  // 閾値 (反応が悪いなら下げる)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  stat = analogRead(1) < threshold ? 0 : 1;
  delay(dly);

  if (stat == 0) {  // スタートビットを受信した場合
    for (int i = 0; i < data_length; i++){
      data[i] = analogRead(1) < threshold ? 0 : 1;
      delay(dly);
    }
    for (int i = data_length - 1; i >= 0; i--) {
      Serial.print(data[i]);
    }
    Serial.println();
  }
}
