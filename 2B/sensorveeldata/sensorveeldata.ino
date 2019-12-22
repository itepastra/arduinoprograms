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

	if (!bme.begin(0x76)) // als de BME280 niet kan initializen geeft ie een error op serial
	{
		Serial.println("kan de BME niet vinden");
	}

	// hier starten we de sdkaart lezer
	Serial.print(" Initializing  SD card ...");
	if (!SD.begin(csPin))
	{
		Serial.println(" initialization  failed !");
		return;
	}
	Serial.println(" initialization  done ."); // Open  the  file  for  WRITING.

	if (rtc.lostPower()) // als de RTC z'n batterij even kwijt was zetten we de tijd op de tijd van compilen
	{
		Serial.println("RTC lost power, lets set the time!");
		// following line sets the RTC to the date & time this sketch was compiled
		rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
	}
	begintijd = rtc.now(); //de tijd waarop we de arduino opstarten is de begintijd

	myFile = SD.open("meetmeer.txt", FILE_WRITE);
	// if the  file  opened  okay , WRITE  to it:
	if (myFile)
	{
		// door deze header die in de file komt bij het opstarten kunnen we ook meteen zien waar de arduino uit is geweest.
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
	DateTime now = rtc.now();		//huidige tijd volgens de RTC
	lastT1 = bme.readTemperature(); // huidige temperatuur volgens de BME
	lastT2 = rtc.getTemperature();  // huidige temperatuur volgens de RTC
	lastP = bme.readPressure();		// huidige druk volgens BME
	lastH = bme.readHumidity();		// huidige luchtvochtigheid volgens de BME

	myFile = SD.open("meetmeer.txt", FILE_WRITE);
	if (myFile)
	{
		n++;
		Serial.println(n);
		myFile.print(String(n) + tab + String(now.unixtime()) + tab + String(lastT1) + tab + String(lastT2) + tab + String(lastP) + tab + String(lastH));
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
