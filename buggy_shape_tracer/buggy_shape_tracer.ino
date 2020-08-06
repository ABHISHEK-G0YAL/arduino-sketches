void setup() {
  for(int i=5;i<=8;i++)
    pinMode(i,OUTPUT);
}
void forward() {
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
void clockwise(float angle) {
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  delay(int(angle*7.50163));
}
void anticlockwise(float angle) {
  digitalWrite(5,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  delay(int(angle*7.50163));
}

void loop() {
  forward();
  delay(1000);//1
  
  anticlockwise(90);
  forward();
  delay(2000);//2
  
  anticlockwise(90);
  forward();
  delay(2000);//3
  
  anticlockwise(90);
  forward();
  delay(2000);//4
  
  anticlockwise(90);
  forward();
  delay(1000);//5
  
  anticlockwise(90);
  forward();
  delay(2000);//6

  anticlockwise(135);
  forward();
  delay(500);//7

  clockwise(45);
  forward();
  delay(500);//8

  anticlockwise(135);
  forward();
  delay(500);//9

  clockwise(90);
  forward();
  delay(500);//10

  anticlockwise(135);
  forward();
  delay(500);//11

  clockwise(45);
  forward();
  delay(500);//12

  anticlockwise(90);
  forward();
  delay(500);//13

  clockwise(45);
  forward();
  delay(500);//14

  anticlockwise(135);
  forward();
  delay(500);//15

  clockwise(90);
  forward();
  delay(500);//16

  anticlockwise(135);
  forward();
  delay(500);//17

  clockwise(45);
  forward();
  delay(500);//18

}