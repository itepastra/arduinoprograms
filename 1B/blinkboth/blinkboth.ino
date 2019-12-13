#include <SoftwareSerial.h>

int LedPin = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(LedPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LedPin, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LedPin, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
}

// dit is een tset