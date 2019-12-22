#include <Wire.h>;            //  enables  hardware  I2C
#include <Adafruit_Sensor.h>; //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h>; //  loads  the  Adafruit

Adafruit_BME280 bme; // This  object  will  control  the  sensor
unsigned int delayT; // Here we store  the  delay  between  msgs
float lastT, lastP, lastH;

int roodLed = 10;
int groenLed = 11;
int blauwLed = 9;

void setup()
{
    Serial.begin(9600);
    // zolang er geen console is blijft de arduino in deze loop
    while (!Serial)
    {
    };

    pinMode(roodLed, OUTPUT);
    pinMode(groenLed, OUTPUT);
    pinMode(blauwLed, OUTPUT);

    // we kijken weer of de sensor online komt
    int status = bme.begin(0x76);
    if (!status)
    {
        Serial.println("couldnt find sensor");
        Serial.print("check wiring, Error:");
        Serial.println(status);
        while (1)
        {
        };
    }

    // als dit alles werkt zijn we blij
    Serial.println("yay t werkt");
    delayT = 5000;
}

void loop()
{
    lastT = bme.readTemperature();
    lastP = bme.readPressure();
    lastH = bme.readHumidity();

    // we printen de temperatuur, druk en luchtvochtigheid
    Serial.println("Data  from  sensor :");
    Serial.print(" Temperature :\t");
    Serial.println(lastT);
    Serial.print(" Pressure :\t");
    Serial.println(lastP);
    Serial.print(" Humidity :\t");
    Serial.println(lastH);
    Serial.println();
    ledjeTemp(lastT);
    ledjeHumid(lastH);
    //  Delay  time  before  next  loopdelay
    delay(delayT);
}

void ledjeTemp(float temp)
{
    digitalWrite(roodLed, LOW);
    digitalWrite(blauwLed, LOW);
    // als het koud is moest de rode led (verwarming) aan
    // als het heet is moest de blauwe led (airco) aan
    if (temp < 23)
    {
        digitalWrite(roodLed, HIGH);
    }
    else if (temp > 28)
    {
        digitalWrite(blauwLed, HIGH);
    }
}

void ledjeHumid(float humid)
{
    digitalWrite(groenLed, LOW);
    // als het niet vochtig genoeg is (sauna ofzo) doen we de groene led (luchtbevochtiger) aan
    if (humid < 65)
    {
        digitalWrite(groenLed, HIGH);
    }
}