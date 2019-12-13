#include <SoftwareSerial.h>

int CurNum = 3; //we slaan 2 over omdat onze functie niet controleerd of een
                //getal deelbaar is door 2 want we voeren hem alleen maar uit op oneven getallen

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("2"); // omdat 2 wel een priemgetal is printen we die toch
    delay(20);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    while (CurNum < 100)
    {
        // put your main code here, to run repeatedly:
        //als de arduino aan een nieuw getal begint knippert het lampje heel kort om dit aan te geven
        digitalWrite(LED_BUILTIN, HIGH);
        delay(10);
        digitalWrite(LED_BUILTIN, LOW);

        if (TestPrime(CurNum))
        {
            Serial.println(String(CurNum));
            digitalWrite(LED_BUILTIN, HIGH);
            delay(CurNum * 10); //we hebben gekozen voor een delay van curnum * 10
        }
        else
        {
            digitalWrite(LED_BUILTIN, LOW);
            delay(CurNum * 10); //de enige rede dat we even lang wachten voor samengestelde getallen is omdat de verhouding anders niet duidelijk is, anders f*ck samengestelde getallen
        }

        CurNum = CurNum + 2; //na een oneven getal komt een even getal en dat is nooit priem, dus waarom zouden we die checken
    }
    Serial.println("all primes are found");
    while (true)
    {
        delay(10000);
        Serial.println("waarom wacht je eigenlijk nog?");
    }
}

bool TestPrime(int curnum)
{
    for (int i = 3; i < curnum; i = i + 2)
    {
        if (i > sqrt(curnum))
        {
            return true;
        }
        if (curnum % i == 0)
        {
            return false;
        }
    }
}

/* dit is de python code waar het uit komt, deze is veel sneller, alleen gebruikt een ding dat de arduino niet goed kan (arrays met variabele lengte)
import math
import datetime

def vindpriem(zoekpriem): #deze functie kijkt of een bepaald getal priem is door te kijken of het deelbaar is door voorgaande priemgetallen
 for primeNumber in primeNumbers:
    if primeNumber > math.ceil(math.sqrt(zoekpriem)): #het is niet nodig om verder te kijken dan de wortel van een priemgetal, dus gaat ie op dat moment uit de functie
      return True
    if zoekpriem % primeNumber == 0:
      return False


start = int(input('vanaf welk getal wil je de priemgetallen hebben? '))
finish = int(input('tot welk getal wil je de priemgetallen hebben? '))
primeNumbers = [5]

i = max(primeNumbers)
t1 = datetime.datetime.now()
while i < finish:
  i += 2
  if vindpriem(i):
    primeNumbers.append(i)
  i += 4
  if vindpriem(i):
    primeNumbers.append(i)

primeNumbers = [2,3] + primeNumbers
displayprimes = [x for x in primeNumbers if x <= finish and x >= start]
t2 = datetime.datetime.now()
print(displayprimes)
print(len(displayprimes))
print(t2-t1)
 */