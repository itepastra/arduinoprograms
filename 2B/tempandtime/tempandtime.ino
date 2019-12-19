// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <RTClib.h>
#include <Wire.h>			 //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit

const unsigned int delayT = 5000;
const String tab = "\t";

RTC_DS3231 rtc;
Adafruit_BME280 bme;
float lastT1, lastT2, lastP, lastH;

void setup()
{

	Serial.begin(9600);

	delay(3000); // wait for console opening

	if (!rtc.begin())
	{
		Serial.println("Couldn't find RTC");
		while (1)
		{
		}
	}
	if (!bme.begin(0x76))
	{
		Serial.println("de klok is kwijt");
	}

	if (rtc.lostPower())
	{
		Serial.println("RTC lost power, lets set the time!");
		// following line sets the RTC to the date & time this sketch was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
		// This line sets the RTC with an explicit date & time, for example to set
		// January 21, 2014 at 3am you would call:
		// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
	}
}

void loop()
{
	DateTime now = rtc.now;
	lastT1 = bme.readTemperature();
	lastT2 = rtc.getTemperature();

	Serial.print("de temperatuur is: ");
	Serial.print(lastT1);
	Serial.print(" C volgens de BME280 en ");
	Serial.print(lastT2);
	Serial.println(" C volgens de RTC");

	delay(delayT);
}
