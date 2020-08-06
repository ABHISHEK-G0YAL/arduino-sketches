#define p1 8
#define p2 9
#define rp 10
#define rn 11
#define lp 12
#define ln 13
bool left_ir,right_ir,pstate_l,pstate_r;
void setup() {
  for(int i=8;i<14;i++)
    pinMode(i,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
}
void move_forward(){
  digitalWrite(lp,HIGH);
  digitalWrite(ln,LOW);
  digitalWrite(rp,HIGH);
  digitalWrite(rn,LOW);
}
void little_left(){
  digitalWrite(lp,LOW);
  digitalWrite(ln,LOW);
  digitalWrite(rp,HIGH);
  digitalWrite(rn,LOW);
}
void left_turn(){
  digitalWrite(lp,LOW);
  digitalWrite(ln,HIGH);
  digitalWrite(rp,HIGH);
  digitalWrite(rn,LOW);
}
void little_right(){
  digitalWrite(lp,HIGH);
  digitalWrite(ln,LOW);
  digitalWrite(rp,LOW);
  digitalWrite(rn,LOW);
}
void right_turn(){
  digitalWrite(lp,HIGH);
  digitalWrite(ln,LOW);
  digitalWrite(rp,LOW);
  digitalWrite(rn,HIGH);
}
void loop() {
  right_ir=digitalRead(A0);
  left_ir=digitalRead(A1);
  if(left_ir && right_ir)
    move_forward();
  else if(right_ir)
    little_right();
  else if(left_ir)
    little_left();
  else {
    if(!pstate_l && !pstate_r);
    else if(pstate_l && pstate_r);
    else if(pstate_l)
      right_turn();
    else if(pstate_r)
      left_turn();
  }
  pstate_l=left_ir;
  pstate_r=right_ir;
  delay(20);
}
