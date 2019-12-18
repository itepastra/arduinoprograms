#include <Wire.h>            //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <SPI.h>
#include <SD.h>

int csPin = 10;
File myFile;
int n = 0;
const unsigned int delayT = 5000;
const String tab = "\t";

Adafruit_BME280 bme; // This  object  will  control  the  sensor
float lastT, lastP, lastH;

void setup()
{
    Serial.begin(9600);
    Serial.print(" Initializing  SD card ...");
    if (!SD.begin(csPin))
    {
        Serial.println(" initialization  failed !");
        return;
    }
    Serial.println(" initialization  done ."); // Open  the  file  for  WRITING.
    del = SD.remove("meet.txt") if (del){
        Serial.println("old file removed")} myFile = SD.open("meet.txt", FILE_WRITE);

    // if the  file  opened  okay , WRITE  to it:
    if (myFile)
    {
        myFile.println("#meting\tmeettijd\ttemp\tpressure\thumidity");
        myFile.close();
    }
    else
    { // if the  file didn ’t open , print  an error:
        Serial.println("error  opening  meet.txt");
    } // Re-open  the  file  for  reading:

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
    lastP = bme.readPressure();
    lastH = bme.readHumidity();

    myFile = SD.open("meet.txt", FILE_WRITE);
    if (myFile)
    {
        n++;
        Serial.println(n);
        myFile.print(n);
        myFile.print(tab);
        myFile.print(millis());
        myFile.print(tab);
        myFile.print(lastT);
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
    if (n > 60)
    {
        Serial.println("klaar");
        while (1)
        {
        }
    }
}