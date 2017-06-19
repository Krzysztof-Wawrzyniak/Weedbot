long czas_wlaczenia_swiatla = 30000;//720000; //12 h wlaczone swiatlo:
void swiatlo()
{
  
  
  digitalWrite(PINswiatlo, LOW);
  delay(czas_wlaczenia_swiatla);
  digitalWrite(PINswiatlo, HIGH);
  delay(86400000 - czas_wlaczenia_swiatla); //24h minus czas włączenia światła
  DiodaSwiatla();
}


