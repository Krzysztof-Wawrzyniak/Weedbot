unsigned long czas_wlaczenia_chlodzenia = 30000;//720000; //12 h wlaczone swiatlo:

void chlodzenie()
{
// temperatura_powietrza = 25;
  if (temperatura_powietrza > 30)
  {
    unsigned long czas_od_ostatniego_resetu_wiatrak = millis();
   
   while( millis() - czas_od_ostatniego_resetu_wiatrak < czas_wlaczenia_chlodzenia)
    digitalWrite(PINwiatrakZewnetrzny, HIGH);
    DiodaWiatrakaZewnetrznego();
  }
}
