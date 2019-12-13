#include <SoftwareSerial.h>

int Red1LedPin = 9;
int Yellow1LedPin = 10;
int Yellow2LedPin = 11;
int Red2LedPin = 12;
int ButtonPin = 8;
int versie = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(Red1LedPin, OUTPUT);
    pinMode(Red2LedPin, OUTPUT);
    pinMode(Yellow1LedPin, OUTPUT);
    pinMode(Yellow2LedPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ButtonPin, INPUT);
}

void loop()
{

    if (digitalRead(ButtonPin))
    {
        versie = (versie + 1) % 2;
    }
    if (versie == 0)
    {
        Serial.println("Versie 0");
        lampjes0();
    }
    else if (versie == 1)
    {
        Serial.println("Versie 1");
        lampjes1();
    }
}

void lampjes0()
{
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(Red1LedPin, HIGH);
    digitalWrite(Red2LedPin, HIGH);
    digitalWrite(Yellow1LedPin, HIGH);
    digitalWrite(Yellow2LedPin, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(Red1LedPin, LOW);
    digitalWrite(Red2LedPin, LOW);
    digitalWrite(Yellow1LedPin, LOW);
    digitalWrite(Yellow2LedPin, LOW);
    delay(500);
}

void lampjes1()
{
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(Red1LedPin, HIGH);
    digitalWrite(Red2LedPin, HIGH);
    digitalWrite(Yellow1LedPin, HIGH);
    digitalWrite(Yellow2LedPin, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(Red1LedPin, LOW);
    digitalWrite(Red2LedPin, LOW);
    digitalWrite(Yellow1LedPin, LOW);
    digitalWrite(Yellow2LedPin, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(Red1LedPin, HIGH);
    digitalWrite(Red2LedPin, HIGH);
    digitalWrite(Yellow1LedPin, HIGH);
    digitalWrite(Yellow2LedPin, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(Red1LedPin, LOW);
    digitalWrite(Red2LedPin, LOW);
    digitalWrite(Yellow1LedPin, LOW);
    digitalWrite(Yellow2LedPin, LOW);
    delay(250);
}
