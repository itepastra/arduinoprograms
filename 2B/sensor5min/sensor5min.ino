#include  <Wire.h>;//  enables  hardware  I2C 
#include  <Adafruit_Sensor.h>;   //  loads  Adafruit  Sensor  definitions
#include  <Adafruit_BME280.h>;   //  loads  the  Adafruit
#include  <SPI.h>;
#include  <SD.h>;


int  csPin = 10;
File  myFile;
int n = 0;
const unsigned int delayT = 5000;

Adafruit_BME280  bme;// This  object  will  control  the  sensor
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
    myFile = SD.open("meet.txt", FILE_WRITE);

    // if the  file  opened  okay , WRITE  to it:
    if (myFile) 
    {
        myFile.println("meting nummer   meettijd     temp     pressure     humidity");
        myFile.close();
    } else {// if the  file didn ’t open , print  an error:
        Serial.println("error  opening  meetwaarden.txt");
    }// Re-open  the  file  for  reading:
    
    int status = bme.begin(0x76);
    if(!status){
        Serial.println("couldnt find sensor");
        Serial.print("check wiring, Error:");
        Serial.println(status);
        while(1){};
    }

}

void loop(){
    n++;
    Serial.println(n);
    lastT = bme.readTemperature();
    lastP = bme.readPressure();
    lastH=bme.readHumidity();

    myFile = SD.open("meetwaarden.txt",FILE_WRITE);
    if (myFile){
        myFile.print(n);
        myFile.print(millis());
        myFile.print(lastT);
        myFile.print(lastP);
        myFile.println(lastH);
        myFile.close();
    }

    delay(delayT);
    if (n>60){
        while (1)
        {
            /* code */
        }
    }
}