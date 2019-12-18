#include  <Wire.h>;//  enables  hardware  I2C 
#include  <Adafruit_Sensor.h>;   //  loads  Adafruit  Sensor  definitions
#include  <Adafruit_BME280.h>;   //  loads  the  Adafruit
#include  <SPI.h>
#include  <SD.h>


int  csPin = 10;
File  myFile;

Adafruit_BME280  bme;// This  object  will  control  the  sensor
unsigned  int  delayT;// Here we store  the  delay  between  msgs
float  lastT , lastP , lastH;

void setup(){
    Serial.begin (9600);
    Serial.print (" Initializing  SD card ...");
    if (!SD.begin(csPin))
    {
        Serial.println (" initialization  failed !");
        return;
    }
    Serial.println (" initialization  done .");// Open  the  file  for  WRITING.
    myFile = SD.open("meetwaarden.txt", FILE_WRITE);

    // if the  file  opened  okay , WRITE  to it:
    if (myFile) 
    {
        myFile.println("meting nummer   meettijd     temp     pressure     humidity");
    } else {// if the  file didn ’t open , print  an error:
        Serial.println("error  opening  test.txt");
    }// Re-open  the  file  for  reading:

}

void loop(){
    
}