#include  <Wire.h>;//  enables  hardware  I2C 
#include  <Adafruit_Sensor.h>;   //  loads  Adafruit  Sensor  definitions
#include  <Adafruit_BME280.h>;   //  loads  the  Adafruit

Adafruit_BME280  bme;// This  object  will  control  the  sensor
unsigned  int  delayT;// Here we store  the  delay  between  msgs
float  lastT , lastP , lastH;

void setup(){
    Serial.begin(9600);
    while(!Serial){};
    int status = bme.begin(0x76);
    if(!status){
        Serial.println("couldnt find sensor");
        Serial.print("check wiring, Error:");
        Serial.println(status);
        while(1){};
    }
    Serial.println("yay t werkt");
    delayT = 5000;
}

void loop(){
    lastT = bme.readTemperature();
    lastP = bme.readPressure();
    lastH=bme.readHumidity();

    Serial.println("Data  from  sensor :");
    Serial.print(" Temperature :\t");
    Serial.println(lastT );
    Serial.print(" Pressure :\t");
    Serial.println(lastP );
    Serial.print(" Humidity :\t");
    Serial.println(lastH );
    Serial.println();

    //  Delay  time  before  next  loopdelay
    delay(delayT);
}
