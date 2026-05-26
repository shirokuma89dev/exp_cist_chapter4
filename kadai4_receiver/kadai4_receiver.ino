#include <Arduino.h>

int inpin = 9;  // 受信用ピン番号
int dly = 100;  // 各ビットの受信間隔（送信側と共通）
int stat;
int data[7];
void setup() {
    pinMode(inpin, INPUT);
    Serial.begin(9600);
}

void loop() {
    stat = digitalRead(inpin);
    Serial.println(stat);
    delay(dly);
    if (stat == 0) {  // スタートビットを受信した場合

        char msg = 0;
        for (int i = 0; i < 7; i++) {
            data[i] = digitalRead(inpin);
            bitWrite(msg, i, data[i]);  // msg の右からi 番
            delay(dly);
        }

        Serial.println(msg);
    }
}
