//Weedbot v.1.0 Beta
//Zautomatyzowana uprawa pomidorow i ziol
//Dolaczenie Bibliotek

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//Deklaracja zmiennych
//Piny urządzeń
int PINswiatlo = 3;
int PINpompa = 4;
int PINwiatrakWewnetrzny = 5;
int PINwiatrakZewnetrzny = 6;
int czujnikDHT11 = A0;

//Diody kolorowe sygnalizujace prace urzadzen
int Dioda_oswietlenia = 8;
int Dioda_pompy = 9;
int Dioda_wiatraka_wewnetrznego = 10;
int Dioda_wiatraka_zewnetrznego = 11; 

#define DHTPIN            2
#define DHTTYPE           DHT11     // DHT 11 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

//Inicjalizacja wyswietlacza
LiquidCrystal_I2C lcd(0x27, 16, 2); // wyswietlacz LCD 16 kolumn i 2 wiersze na adresie 0x27

void setup()
{
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  pinMode(czujnikDHT11, INPUT);
  pinMode(PINpompa, OUTPUT);
  pinMode(PINswiatlo, OUTPUT);
  pinMode(PINwiatrakWewnetrzny, OUTPUT);
  pinMode(PINwiatrakZewnetrzny, OUTPUT);
  pinMode(Dioda_oswietlenia, OUTPUT);
  pinMode(Dioda_pompy, OUTPUT);
  pinMode(Dioda_wiatraka_wewnetrznego, OUTPUT);
  pinMode(Dioda_wiatraka_zewnetrznego,OUTPUT); 

}
void loop()
{
  CzujnikDHT11();
  wilgotnosc_gleby();
  chlodzenie();
  swiatlo();
  podlewanie();
}
