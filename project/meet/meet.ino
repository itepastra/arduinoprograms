#include <SoftwareSerial.h>
#include <Wire.h>			 //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <SPI.h>
#include <SD.h>

const String tab = "\t";
const int csPin = 10;
const int AnalogMicIn = A0;
const int DigitalMicIn = 7;
const int sampleWindow = 4500;
unsigned int sample;
const SoftwareSerial CSerial(2, 3);
const byte message[] = {0XFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};

File myFile;
int n = 0;
Adafruit_BME280 bme;
float lastT, lastP, lastH, analog;
int digital;
byte sensorValueH = 0;
byte sensorValueL = 0;
byte Temperature = 0;
int sensorValue = 0;

void setup()
{
	pinMode(AnalogMicIn, INPUT);
	pinMode(DigitalMicIn, INPUT);

	delay(3000); // wait for console opening

	Serial.begin(9600); // Serial output with 9600 bps

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

	myFile = SD.open("meetales.txt", FILE_WRITE);
	// if the  file  opened  okay , WRITE  to it:
	if (myFile)
	{
		// door deze header die in de file komt bij het opstarten kunnen we ook meteen zien waar de arduino uit is geweest.
		myFile.println("#\tmillis\ttemp\thumidity\tpressure\tanalog\tdigital");
		myFile.close();
	}
	else
	{ // if the  file didn ’t open , print  an error:
		Serial.println("error  opening  meetmeer.txt");
	} // Re-open  the  file  for  reading:

	CSerial.begin(9600);
	CSerial.listen();
}

void loop()
{
	analog = analogread(AnalogMicIn);
	digital = digitalread(DigitalMicIn);

	Serial.println("Entering loop!");

	CSerial.write(message, sizeof(message));

	Serial.println("Message sent!");
	delay(500);
	for (int i = 0; i < 9; i++)
	{
		Serial.println("In loop");
		while (!CSerial.available())
			;
		// wait for a character
		Serial.println("Rcv");
		int incomingByte = CSerial.read();
		Serial.print(incomingByte, HEX);
		Serial.print(' ');
		if (i == 2)
			sensorValueH = incomingByte;
		if (i == 3)
			sensorValueL = incomingByte;
		if (i == 4)
			Temperature = incomingByte;
	}
	sensorValue = sensorValueH * 256 + sensorValueL;

	myFile = SD.open("meetales.txt", FILE_WRITE);
	if (myFile)
	{
		n++;
		myFile.print(n);
		myFile.print(tab);
		myFile.print(millis());
		myFile.print(tab);
		myFile.print(bme.readTemperature());
		myFile.print(tab);
		myFile.print(bme.readHumidity());
		myFile.print(tab);
		myFile.print(bme.readPressure());
		myFile.print(tab);
		myFile.print(sensorValue);
		myFile.print(tab);
		myFile.print(analog);
		myFile.print(tab);
		myFile.print(digital));
		myFile.close();
	}
	else
	{
		Serial.println("file fout");
	}

}