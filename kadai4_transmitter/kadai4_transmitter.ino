#include <Arduino.h>

// #define TRANSMITTER

#ifdef TRANSMITTER

int outpin = 8;
byte data = B10;
int dly = 100;
int dly2 = 500;

const char msg = 'A';

void setup() {
    pinMode(outpin, OUTPUT);
    digitalWrite(outpin, HIGH);
}

void loop() {
    digitalWrite(outpin, 0);  // スタートビット（0）の送信
    delay(dly);
    for (int i = 0; i < 7; i++) {
        digitalWrite(outpin,
                     bitRead(msg, i));  // msg の右からi 番目のビットを送信
        delay(dly);
    }
    digitalWrite(outpin, 1);  // ストップビット（1）の送信
    delay(dly2);
}

#else

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

#endif
