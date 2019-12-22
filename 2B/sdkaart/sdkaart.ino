/** The  circuit:* SD card  attached  to SPI  bus as  follows:
 * MOSI - pin 11   |MISO - pin 12   | 
 * These  pins  are  connected  to the  hardware SPI -busCLK   - pin 13   
 * |CS - pin 10- This  pin can be  chosen**/

#include <SPI.h>
#include <SD.h>

const int csPin = 10; // this is the pin on the arduino connected to the cs pin on the sd card reader
File myFile;

void setup()
{ // Open  serial  communications  and  wait  for  port to open:
    Serial.begin(9600);
    Serial.print(" Initializing  SD card ...");
    if (!SD.begin(csPin))
    {
        Serial.println(" initialization  failed !");
        return;
    }
    Serial.println(" initialization  done ."); // Open  the  file  for  WRITING.
    myFile = SD.open("test.txt", FILE_WRITE);

    // if the  file  opened  okay , WRITE  to it:
    if (myFile)
    {
        Serial.print(" Writing  to test.txt ...");
        myFile.println(" testing 1, 2, 3."); // close  the  file:
        myFile.close();
        Serial.println(" Writing  to the  file  done !");
    }
    else
    { // if the  file didn ’t open , print  an error:
        Serial.println("error  opening  test.txt");
    } // Re-open  the  file  for  reading:
    myFile = SD.open("test.txt");
    if (myFile)
    {
        Serial.println("In the  file  test.txt :"); // read  from  the  file  until  there ’s nothing  else in it:
        while (myFile.available())
        {
            Serial.write(myFile.read());
        } // close  the
    file:
        myFile.close();
    }
    else
    { // if the  file didn ’t open , print  an error:
        Serial.println("error  opening  test.txt");
    }
}

void loop()
{
}