//Weedbot v.1.0 Beta
//Zautomatyzowana uprawa pomidorow i ziol
//Dolaczenie Bibliotek

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>

//Deklaracja zmiennych

int pompa = 3;
long czas_wlaczenia_swiatla = 1000;//720000; //12 h wlaczone swiatlo:
int PINswiatlo = 7;
int PINchlodzenie = 4;
long czas_wlaczenia_chlodzenia =2000; //60000;
float wilgotnosc_powietrza;
float temperatura_powietrza;
int czujnikDHT11 = A2;

#define DHTPIN            2
#define DHTTYPE           DHT11     // DHT 11 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

// czas pomiedzy pomiarami 5min - 300.000ms
#define ODSTEP 1000
// limit po ilu odczytach liczmy srednia
#define LIMIT_ODCZYTOW 20

// informacje o odczytach
int suma_odczytow = 0;
int liczba_odczytow = 0;
unsigned long czas_poprzedni = 0;

//Inicjalizacja wyswietlacza
LiquidCrystal_I2C lcd(0x27, 16, 2); // wyswietlacz LCD 16 kolumn i 2 wiersze na adresie 0x27

void setup()
{
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
  pinMode(czujnikDHT11, INPUT);
  pinMode(pompa, OUTPUT);

}
void CzujnikDHT11()
{
  //Odczyt temperatury i wilgotności z czujnika DHT11
  lcd.clear();
  wilgotnosc_powietrza = dht.readHumidity();
  temperatura_powietrza = dht.readTemperature();


  lcd.setCursor(0, 0); lcd.print("Temp: ");  lcd.print(temperatura_powietrza); lcd.print(" *C"); //Wydruk Temperatury Powietrza na wyswietlaczu LCD
  lcd.setCursor(0, 1); lcd.print("Wilg: ");  lcd.print(wilgotnosc_powietrza); lcd.print(" %"); //Wydruk Wilgotnosci powietrza na wyswietlaczu LCD
  delay(5000);
}

void wilgotnosc_gleby()
{
  // czas liczony od momentu wlaczenia urzadzenia
  unsigned long czas_aktualny = millis();

  // sprawdza czy uplynal juz okreslony czas miedzy pomiarami
  if (czas_aktualny - czas_poprzedni > ODSTEP)
  {
    czas_poprzedni = czas_aktualny;

    // dodajemy odczyt
    liczba_odczytow += 1;

    // Odczytaj wartosc z czujnika wilgotnosci gleby:
    int  wartosc_odczytu = analogRead(A0);

    // mapowanie wartosci odczytu do skali wilgotnosc 0 do 100%:

    int wilgotnosc_gleby = map(wartosc_odczytu, 1023, 0, 0, 100);

    // sumujemy odczyty
    suma_odczytow += wilgotnosc_gleby;

    int srednia = ceil(suma_odczytow / liczba_odczytow);
    // zerowanie licznikow
    liczba_odczytow = suma_odczytow = 0;
    if (srednia < 50)
    {
      digitalWrite(pompa, HIGH);
      delay(5000);
      digitalWrite(pompa, LOW);
    }
  }
}
void swiatlo()
{
  digitalWrite(PINswiatlo, HIGH);
  delay(czas_wlaczenia_swiatla);
  digitalWrite(PINswiatlo, LOW);
}

void chlodzenie()
{
  if (temperatura_powietrza > 30)
  {
    digitalWrite(PINchlodzenie, HIGH);
    delay(czas_wlaczenia_chlodzenia);
    digitalWrite(PINchlodzenie, LOW);
  }
}
void loop()
{
  CzujnikDHT11();
  wilgotnosc_gleby();
  swiatlo();
  chlodzenie();
}

