#include <Arduino.h>

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

