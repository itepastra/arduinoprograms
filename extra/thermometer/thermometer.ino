#include <Wire.h>            //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_BME280 bme;       // This  object  will  control  the  sensor
unsigned int delayT = 100; // Here we store  the  delay  between  msgs
float lastT, lastH;

void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the first line of the LCD.
    lcd.setCursor(0, 0);
    lcd.print("temp: ");
    // pirnt a message on the second line of the lcd
    lcd.setCursor(0, 1);
    lcd.print("humid: ");

    //initialize the sensor
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
}

void loop()
{
    lastT = bme.readTemperature();
    lastH = bme.readHumidity();

    // we want the message to keep displaying so we start writing after it.
    lcd.setCursor(6, 0);
    lcd.print(lastT);
    // we also want to display the humidity so we set the cursor and print to the lcd.
    lcd.setCursor(7, 1);
    lcd.print(lastH);

    //we wait for delayT milliseconds every loop
    delay(delayT);
}
