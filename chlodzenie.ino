void chlodzenie()
{
// temperatura_powietrza = 25;
  if (temperatura_powietrza > 30)
  {
    digitalWrite(PINwiatrakZewnetrzny, LOW);
    delay(czas_wlaczenia_chlodzenia);
    digitalWrite(PINwiatrakZewnetrzny, HIGH);
    DiodaWiatrakaZewnetrznego();
  }
}
