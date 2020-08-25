#define d 50

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(d);
  digitalWrite(12, LOW);
  delay(d);
  digitalWrite(12, HIGH);
  delay(d);
  digitalWrite(13, LOW);
  delay(d);
  digitalWrite(11, HIGH);
  delay(d);
  digitalWrite(12, LOW);
  delay(d);
  digitalWrite(10, HIGH);
  delay(d);
  digitalWrite(11, LOW);
  delay(d);
  digitalWrite(9, HIGH);
  delay(d);
  digitalWrite(10, LOW);
  delay(d);
  digitalWrite(10, HIGH);
  delay(d);
  digitalWrite(9, LOW);
  delay(d);
  digitalWrite(11, HIGH);
  delay(d);
  digitalWrite(10, LOW);
  delay(d);
  digitalWrite(12, HIGH);
  delay(d);
  digitalWrite(11, LOW);
  delay(d);
}