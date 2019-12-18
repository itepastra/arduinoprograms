#include  <Wire.h>;//  enables  hardware  I2C 
#include  <Adafruit_Sensor.h>;   //  loads  Adafruit  Sensor  definitions
#include  <Adafruit_BME280.h>;   //  loads  the  Adafruit

Adafruit_BME280  bme;// This  object  will  control  the  sensor
unsigned  int  delayT;// Here we store  the  delay  between  msgs
float  lastT , lastP , lastH;

int roodLed = 10;
int groenLed = 11;
int blauwLed = 9;


void setup(){
    Serial.begin(9600);
    while(!Serial){};

    pinMode(roodLed,OUTPUT);
    pinMode(groenLed,OUTPUT);
    pinMode(blauwLed,OUTPUT);


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
    ledjeTemp(lastT);
    ledjeHumid(lastH);
    //  Delay  time  before  next  loopdelay
    delay(delayT);
}


void ledjeTemp(float temp){
    digitalWrite(roodLed, LOW);
    digitalWrite(blauwLed,LOW);
    if (temp < 23){
        digitalWrite(roodLed,HIGH);
    } else if (temp > 28){
        digitalWrite(blauwLed,HIGH);
    }

}

void ledjeHumid(float humid){
    digitalWrite(groenLed,LOW);
    if (humid < 65){
        digitalWrite(groenLed,HIGH);
    }
}