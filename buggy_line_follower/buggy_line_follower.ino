#include <NewPing.h>
#define lp 5
#define ln 6
#define rp 8
#define rn 7
#define l_ir A0
#define r_ir A1
#define g_pin A4
#define Trig_pin 13
#define Echo_pin 12
#define Max_dist 20
bool left_ir,right_ir,start=false,parked=false;
int gantry_1=0,gantry_2=0,gantry_3=0,parking_n=0;
NewPing echo(Trig_pin,Echo_pin,Max_dist);
void setup() {
  for(int i=5;i<9;i++)
    pinMode(i,OUTPUT);
  pinMode(l_ir,INPUT);
  pinMode(r_ir,INPUT);
  Serial.begin(9600);
  Serial.println("connected");
}
void loop() {
  if(!start) {
    if(Serial.available()>0) {
      switch(Serial.read()) {
        case 's': start=true;
      }
    }
  }
  else {
    follow_line(2);
    left_blind();
  }
}
void follow_line(int rounds) {
  while(gantry_sum()<(rounds*3)) {
    check_obstacle();
    left_ir=digitalRead(l_ir);
    right_ir=digitalRead(r_ir);
    Serial.println(left_ir);
    if(left_ir && right_ir)
      move_forward();
    else if(right_ir)
      little_left();
    else if(left_ir)
      little_right();
    else
      stop_buggy();
    count_gantry();
  }
}
void left_blind() {
  while(!parked) {
    right_ir=digitalRead(r_ir);
    if(right_ir) little_left();
    else little_right;
    check_parking();
  }
}
void check_parking() {
  left_ir=digitalRead(l_ir);
  right_ir=digitalRead(r_ir);
  if(!left_ir && !right_ir) {
    ++parking_n;
    parked=true;
    stop_buggy();
  }
}
int gantry_sum() {
  return gantry_1+gantry_2+gantry_3;
}
void check_obstacle() {
  while(echo.ping_cm()) stop_buggy();
}
void count_gantry() {
  if (digitalRead(g_pin)==HIGH) {
    unsigned long d = pulseIn(g_pin,HIGH);
    if(d > 500 and d < 1500) {
      Serial.println("Gantry: 1");
      ++gantry_1;
      stop_buggy();
      delay(1000);
    }
    else if (d> 1500 and d < 2500) {
      Serial.println("Gantry: 2");
      ++gantry_2;
      stop_buggy();
      delay(1000);
    }
    else if (d > 2500 and d < 3500) {
      Serial.println("Gantry: 3");
      ++gantry_3;
      stop_buggy();
      delay(1000);
    }
    else
      Serial.println("Gantry: Unknown");
  }
}
void stop_buggy() {
  digitalWrite(lp,LOW);
  digitalWrite(ln,LOW);
  digitalWrite(rp,LOW);
  digitalWrite(rn,LOW);
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
