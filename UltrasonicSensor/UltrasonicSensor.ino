void setup() {
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  float br,cm,in,dur = pulseIn(3, HIGH);
  cm =(dur/2)/29.1;
  in =(dur/2)/74;
  if(cm>16) br=0;
  else br=256-(cm*16);
  analogWrite(9,br);
  Serial.print(br);
  Serial.print(" br, ");
  Serial.print(in);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(250);
}
