void zegar()
{
  tmElements_t tm; 
 
  Serial.print("Sec: "); Serial.println(sekunda);   
  if (RTC.read(tm)) {
  godzina = tm.Hour; minuta = tm.Minute; sekunda = tm.Second; rok = tm.Year; miesiac = tm.Month; dzien = tm.Day; 
   wyswietlacz();
    
  } else {
    if (RTC.chipPresent()) {
      lcd.println("DS1307 stoi. Uruchom Zegar");
      } 
       else {
      lcd.println("DS1307 blad oczczytu!"); lcd.println("sprawdz polaczenie");
    }
    delay(9000);
  }
  delay(1000);
}

