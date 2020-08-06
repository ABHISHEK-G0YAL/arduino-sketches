
void setup() {
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);
}
void loop() {
  bool chk=0;
  chk=digitalRead(5);
  if(chk)
  digitalWrite(10, HIGH);
  else
  digitalWrite(10, LOW);
}
