#include <SoftwareSerial.h>

int LedPin1 = 6;
int LedPin2 = 11;
int LedPin3 = 10;
int LedPin4 = 9;
int ButtonPin = 2;
int versie = 4;
const int VersieAantal = 9;

void setup()
{
    Serial.begin(9600);
    pinMode(LedPin1, OUTPUT);
    pinMode(LedPin4, OUTPUT);
    pinMode(LedPin2, OUTPUT);
    pinMode(LedPin3, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ButtonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(ButtonPin), InterruptSwitch, RISING);
}

void loop()
{

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
    else if (versie == 2)
    {
        Serial.println("Versie 2");
        lampjes2();
    }
    else if (versie == 3)
    {
        Serial.println("Versie 3");
        lampjes3();
    }
    else if (versie == 4)
    {
        Serial.println("Versie 4");
        lampjes4();
    }
    else if (versie == 5)
    {
        Serial.println("Versie 5");
        lampjes5();
    }else if (versie == 6)
    {
        Serial.println("Versie 6");
        lampjes6();
    }else if (versie == 7)
    {
        Serial.println("Versie 7");
        lampjes7();
    }else if (versie == 8)
    {
        Serial.println("Versie 8");
        lampjes8();
    }
}

void InterruptSwitch()
{
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 200)
 {
   versie = (versie + 1) % VersieAantal;
 }
 last_interrupt_time = interrupt_time;
}
    


void lampjes0()
{
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin4, HIGH);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin4, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    delay(500);
}

void lampjes1()
{
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin4, HIGH);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin4, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LedPin1, HIGH);
    digitalWrite(LedPin4, HIGH);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LedPin1, LOW);
    digitalWrite(LedPin4, LOW);
    digitalWrite(LedPin2, LOW);
    digitalWrite(LedPin3, LOW);
    delay(250);
}

void lampjes2()
{
    digitalWrite(LedPin1, HIGH);
    delay(250);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin1, LOW);
    delay(250);
    digitalWrite(LedPin3, HIGH);
    digitalWrite(LedPin2, LOW);
    delay(250);
    digitalWrite(LedPin4, HIGH);
    digitalWrite(LedPin3, LOW);
    delay(250);
    digitalWrite(LedPin4, LOW);
}

void lampjes3()
{
    digitalWrite(LedPin1, HIGH);
    delay(166);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin1, LOW);
    delay(166);
    digitalWrite(LedPin3, HIGH);
    digitalWrite(LedPin2, LOW);
    delay(166);
    digitalWrite(LedPin4, HIGH);
    digitalWrite(LedPin3, LOW);
    delay(166);
    digitalWrite(LedPin4, LOW);
    digitalWrite(LedPin3, HIGH);
    delay(166);
    digitalWrite(LedPin2, HIGH);
    digitalWrite(LedPin3, LOW);
    delay(166);
    digitalWrite(LedPin2, LOW);
}

void lampjes4()
{
    for (int i = 0; i < 256; i++)
    {
        analogWrite(LedPin1, i % 256);
        analogWrite(LedPin2, (i + 64) % 256);
        analogWrite(LedPin3, (i + 128) % 256);
        analogWrite(LedPin4, (i + 192) % 256);
        delay(4);
    }
}

void lampjes5(){
    for (int i = 0; i < 512; i++)
    {
        analogWrite(LedPin1, i % 256);
        analogWrite(LedPin2, (i + 128) % 256);
        analogWrite(LedPin3, i% 256);
        analogWrite(LedPin4, (i + 128) % 256);
        delay(2);
    }
}

void lampjes6(){
    digitalWrite(LedPin1,HIGH);
    digitalWrite(LedPin3,HIGH);
    delay(250);
    digitalWrite(LedPin1,LOW);
    digitalWrite(LedPin2,HIGH);
    digitalWrite(LedPin3,LOW);
    digitalWrite(LedPin4,HIGH);
    delay(250);
    digitalWrite(LedPin2,LOW);
    digitalWrite(LedPin4,LOW);

}
void lampjes7(){
    digitalWrite(LedPin1,HIGH);
    delay(100);
    digitalWrite(LedPin2,HIGH);
    delay(100);
    digitalWrite(LedPin3,HIGH);
    delay(100);
    digitalWrite(LedPin4,HIGH);
    delay(100);
    digitalWrite(LedPin1,LOW);
    delay(100);
    digitalWrite(LedPin2,LOW);
    delay(100);
    digitalWrite(LedPin3,LOW);
    delay(100);
    digitalWrite(LedPin4,LOW);
    delay(100);
}

void lampjes8(){
    for (int i = 0; i < 512; i++)
    {
        analogWrite(LedPin1, i % 256);
        analogWrite(LedPin2, (i + 128) % 256);
        analogWrite(LedPin3, (i% 256));
        analogWrite(LedPin4, (i + 128) % 256);
        delay(2);
    }
}