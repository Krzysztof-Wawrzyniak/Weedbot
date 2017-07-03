
void wyswietlacz(){

    lcd.setCursor (0, 0); LCDprint2digits(godzina); lcd.print(':'); LCDprint2digits(minuta);// lcd.print(':'); LCDprint2digits(sekunda);
    lcd.setCursor (0, 1); lcd.print(dzien); lcd.print('/'); lcd.print(monthName[miesiac-1]);// lcd.print('/'); lcd.print(tmYearToCalendar(rok));
    lcd.setCursor (5,0); lcd.print("T:"); lcd.print(TemperaturaPowietrza);lcd.print("C");
    lcd.setCursor (5,1); lcd.print("W:"); lcd.print(WilgotnoscPowietrza); lcd.print("%");
    lcd.setCursor (11,0); lcd.print("G:"); lcd.print(WilgotnoscGleby); lcd.print("%");

   }
void LCDprint2digits(int number) {
  if (number >= 0 && number < 10) {
    lcd.write('0');
  }
  lcd.print(number);  
}

