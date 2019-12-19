// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <RTClib.h>
#include <Wire.h>			 //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <SPI.h>
#include <SD.h>

const unsigned int delayT = 5000;
const String tab = "\t";
const int csPin = 10;
const DateTime begintijd;
File myFile;
int n = 0;

RTC_DS3231 rtc;
Adafruit_BME280 bme;
float lastT1, lastT2, lastP, lastH;

void setup()
{

	Serial.begin(9600);

	delay(3000); // wait for console opening

	if (!bme.begin(0x76))
	{
		Serial.println("de klok is kwijt");
	}
	Serial.print(" Initializing  SD card ...");
	if (!SD.begin(csPin))
	{
		Serial.println(" initialization  failed !");
		return;
	}
	Serial.println(" initialization  done ."); // Open  the  file  for  WRITING.

	if (rtc.lostPower())
	{
		Serial.println("RTC lost power, lets set the time!");
		// following line sets the RTC to the date & time this sketch was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
		// This line sets the RTC with an explicit date & time, for example to set
		// January 21, 2014 at 3am you would call:
		// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
	}
	begintijd = rtc.now(); //de tijd waarop we de arduino opstarten is de begintijd

	myFile = SD.open("meetmeer.txt", FILE_WRITE);
	// if the  file  opened  okay , WRITE  to it:
	if (myFile)
	{
		// door deze header die onderaan de file komt kunnen we ook meteen zien waar de arduino uit is geweest.
		myFile.println("#" + String(begintijd.unixtime()) + "\tmeting\tmeettijd\ttemp\tpressure\thumidity");
		myFile.close();
	}
	else
	{ // if the  file didn ’t open , print  an error:
		Serial.println("error  opening  meetmeer.txt");
	} // Re-open  the  file  for  reading:
}

void loop()
{
	DateTime now = rtc.now();
	lastT1 = bme.readTemperature();
	lastT2 = rtc.getTemperature();
	lastP = bme.readPressure();
	lastH = bme.readHumidity();

	myFile = SD.open("meetmeer.txt", FILE_WRITE);
	if (myFile)
	{
		n++;
		Serial.println(n);
		myFile.print(n);
		myFile.print(tab);
		myFile.print(now.unixtime());
		myFile.print(tab);
		myFile.print(lastT1);
		myFile.print(tab);
		myFile.print(lastT2);
		myFile.print(tab);
		myFile.print(lastP);
		myFile.print(tab);
		myFile.println(lastH);
		myFile.close();
	}
	else
	{
		Serial.println("file fout");
	}

	delay(delayT);
	// als het verschil in tijd met het begin meer dan 900 seconden is is het 15 minuten
	if ((now.unixtime() - begintijd.unixtime()) > 900)
	{
		while (true)
		{
		}
	}
}
