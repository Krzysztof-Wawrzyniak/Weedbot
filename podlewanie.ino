unsigned long czas_wlaczenia_podlewania = 30000;

void podlewanie()
{
  unsigned long czas_od_ostatniego_resetu_pompa = millis();

  while( millis() - czas_od_ostatniego_resetu_pompa < czas_wlaczenia_podlewania)
  {
    digitalWrite(PINpompa, HIGH);
    DiodaPompy();
  }
   
}
