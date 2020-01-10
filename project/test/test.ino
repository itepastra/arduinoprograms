/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 2 (connect to TX of other device)
 * TX is digital pin 3 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_BME280 bme;

byte sensorValueH = 0;
byte sensorValueL = 0;
byte Temperature = 0;
int sensorValue = 0;

void setup()
{
	// Open serial communications and wait for port to open:
	Serial.begin(9600);
	//while (!Serial) {
	//; // wait for serial port to connect. Needed for Native USB only
	//}

	if (!bme.begin(0x76))
	{
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
	}
	Serial.println("Goodnight moon!");

	// set the data rate for the SoftwareSerial port
	mySerial.begin(9600);
	mySerial.listen();
}

/*void loop ()
{
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);

  
}*/

void loop() // run over and over
{
	Serial.println("Entering loop!");
	byte message[] = {0XFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
	mySerial.write(message, sizeof(message));

	Serial.println("Message sent!");
	delay(500);
	for (int i = 0; i < 9; i++)
	{
		//Serial.println("In loop");
		while (!mySerial.available())
			;
		// wait for a character
		//Serial.println("Rcv");
		int incomingByte = mySerial.read();
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
	Serial.println();
	Serial.print("CO2 concentration: ");
	Serial.print(sensorValue);
	Serial.print("\nTMH-19: ");
	Serial.print(Temperature - 40);
	Serial.print("\tTBME280: ");
	Serial.println(bme.readTemperature());
	Serial.print("PBME280: ");
	Serial.println(bme.readPressure() / 100.0F);
	Serial.print("HBME280: ");
	Serial.println(bme.readHumidity());
	Serial.println();

	delay(4500);
}
