unsigned long czas_wlaczenia_swiatla = 30000;//720000; //12 h wlaczone swiatlo:
void swiatlo()
{
unsigned long czas_od_ostatniego_resetu_lampa = millis();

  while( millis() - czas_od_ostatniego_resetu_lampa < czas_wlaczenia_swiatla)
  {
    digitalWrite(PINswiatlo, HIGH);
    DiodaSwiatla();
  }
  //digitalWrite(PINswiatlo, HIGH);
}


