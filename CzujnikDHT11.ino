int wilgotnosc_powietrza;
int temperatura_powietrza;
void CzujnikDHT11()
{
  //Odczyt temperatury i wilgotności z czujnika DHT11
  lcd.clear();

  wilgotnosc_powietrza = dht.readHumidity();
  temperatura_powietrza = dht.readTemperature();
    
// Testowanie na porcie szeregowym___________________________________________________________________________________________________________
    Serial.print("Temp: ");
    Serial.println(temperatura_powietrza);
    Serial.print("Wilg: ");
    Serial.println(wilgotnosc_powietrza);
// Testowanie na porcie szeregowym___________________________________________________________________________________________________________


  lcd.setCursor(0, 0); lcd.print("Temp: ");  lcd.print(temperatura_powietrza); lcd.print(" *C"); //Wydruk Temperatury Powietrza na wyswietlaczu LCD
  lcd.setCursor(0, 1); lcd.print("Wilg: ");  lcd.print(wilgotnosc_powietrza); lcd.print(" %"); //Wydruk Wilgotnosci powietrza na wyswietlaczu LCD
  delay(5000);
}


