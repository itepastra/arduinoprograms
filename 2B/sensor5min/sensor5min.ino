#include <Wire.h>            //  enables  hardware  I2C
#include <Adafruit_Sensor.h> //  loads  Adafruit  Sensor  definitions
#include <Adafruit_BME280.h> //  loads  the  Adafruit
#include <SPI.h>
#include <SD.h>

int csPin = 10; // dit is de pin die aan de CS pin van de sdkaartlezer zit
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

    del = SD.remove("meet.txt"); // we verwijderen de oude meet.txt zodat we altijd met een leeg bestand beginnen
    if (del)                     // dit is waar als het bestand kon worden verwijdert
    {
        Serial.println("old file removed")
    }
    myFile = SD.open("meet.txt", FILE_WRITE); //  hier openen we meet.txt vervolgens weer

    // if the  file  opened  okay , WRITE  to it:
    if (myFile)
    {
        myFile.println("#meting\tmeettijd\ttemp\tpressure\thumidity"); // we maken een header zodat we de data kunnen lezen
        myFile.close();
    }
    else
    { // if the  file didn ’t open , print  an error:
        Serial.println("error  opening  meet.txt");
    } // Re-open  the  file  for  reading:

    int status = bme.begin(0x76); // als de bme niet kan beginnen printen we dit en gaan we in een infinite loop
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
        myFile.print(String(n) + tab + String(millis()) + tab + String(lastT) + tab + String(lastP) + tab + String(lastH));
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