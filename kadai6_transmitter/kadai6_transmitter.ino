int outpin = 2;   // 送信用 ピン番号
int data_length = 7;   // 送信データ長
byte data = B0100101;  // 送信データ (10進数の37)
int dly = 100;    // 各ビットの送信間隔 (100, 20, 5)
int dly2 = 500;   // データの送信間隔

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outpin, OUTPUT);
  digitalWrite(outpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outpin, 0);  // Send start bit (0)
  Serial.println("0 (Start)");
  delay(dly);

  for (int i = 0; i < 7; i++) {
    digitalWrite(outpin, bitRead(data, i));
    Serial.println(bitRead(data, i));  // Send No.i bit from right on data
    delay(dly);
  }
  digitalWrite(outpin, 1);  // Send stop bit (1);
  Serial.println("1 (End)");
  delay(dly2);
}
