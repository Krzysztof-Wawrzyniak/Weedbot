// czas pomiedzy pomiarami 5min - 300.000ms
#define ODSTEP 1000
// limit po ilu odczytach liczmy srednia
#define LIMIT_ODCZYTOW 20

// informacje o odczytach wilgotnosci gleby do czujnika wilgotnosci gleby
int suma_odczytow = 0;
int liczba_odczytow = 0;
unsigned long czas_poprzedni = 0;

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
// Testowanie na porcie szeregowym___________________________________________________________________________________________________________
    Serial.print("Soil ");
    Serial.println(wilgotnosc_gleby);
// Testowanie na porcie szeregowym___________________________________________________________________________________________________________

    // wypisanie na wyswtietlaczu LCD
    lcd.setCursor(0, 10); lcd.print("Soil: ");  lcd.print(wilgotnosc_gleby); lcd.print(" %"); //Wydruk Wilgotnosci gleby na wyswietlaczu LCD
    // sumujemy odczyty
    suma_odczytow += wilgotnosc_gleby;

    int srednia = ceil(suma_odczytow / liczba_odczytow);
    // zerowanie licznikow
    liczba_odczytow = suma_odczytow = 0;
    if (srednia < 50)
    {
      podlewanie();
    }
  }
}
