#include <Wire.h>            //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Adafruit_BME280  bme;// This  object  will  control  the  sensor
unsigned  int  delayT = 100;// Here we store  the  delay  between  msgs
float  lastT , lastP , lastH;


void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("temp: ");
    lcd.setCursor(0,1);
    lcd.print("humid: ");
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

    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(6, 0);
    lcd.print(lastT);
    lcd.setCursor(7,1);
    lcd.print(lastH);
    // print the number of seconds since reset:
    delay(delayT);
}
