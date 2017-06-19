void podlewanie()
{
  digitalWrite(PINpompa, HIGH);
  delay(czas_podlewania);
  digitalWrite(PINpompa, LOW);
  DiodaPompy();
}
