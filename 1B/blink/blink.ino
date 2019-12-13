#include <SoftwareSerial.h>

int LedPin = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
}

void loop()
{
    digitalWrite(LedPin, HIGH);
    delay(500);
    digitalWrite(LedPin, LOW);
    delay(500);
}