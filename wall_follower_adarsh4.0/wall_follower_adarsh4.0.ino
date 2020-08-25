/*--------Ultrasonics----------*/
#define echoPin_R 7   // Echo Pin RIGHT
#define trigPin_R 13  // Trigger Pin RIGHT

#define echoPin_M 12   //Echo Pin Middle
#define trigPin_M 4  //Trigger Pin Middle

/*-------definning Outputs------*/
#define LM1  11   // left motor
#define LM2  3   // left motor                                     
#define RM1  6   // right motor
#define RM2  5   // right motor
float dm;
float dr;
float x=25;//distance of seperation
float y=10;//distance of seperation


float dist_m()
{
  float distance,duration;
  digitalWrite(trigPin_M, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin_M, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin_M, LOW);
  duration= pulseIn(echoPin_M, HIGH);
  distance= duration/58.2;
  return distance;
}

float dist_r()
{
  float distance,duration;
  digitalWrite(trigPin_R, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin_R, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin_R, LOW);
  duration= pulseIn(echoPin_R, HIGH);
  distance= duration/58.2;
  return distance;
}

void turn_left_hard()
{
  analogWrite(LM1, 0);
  analogWrite(LM2, 50);
  analogWrite(RM1, 255);
  analogWrite(RM2, 0);
}

void turn_left_soft()
{
  analogWrite(LM1, 100);
  analogWrite(LM2, 0);
  analogWrite(RM1, 150);
  analogWrite(RM2, 0);
}

void turn_right_hard()
{
  analogWrite(LM1, 255);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0 );
  analogWrite(RM2, 255);
}

void turn_right_soft()
{
  analogWrite(LM1, 150);
  analogWrite(LM2, 0);
  analogWrite(RM1, 100 );
  analogWrite(RM2, 0);
}

void move_forward()
{
  analogWrite(LM1, 255);
  analogWrite(LM2, 0);
  analogWrite(RM1, 255 );
  analogWrite(RM2, 0);
}

void move_stop()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW );
  digitalWrite(RM2, LOW);
  //delay(1000);
}
void setup() 
{
  Serial.begin(9600); 
  /*---MOTORS---*/
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  /*---ULTRASONICS---*/
  pinMode(trigPin_R, OUTPUT);
  pinMode(echoPin_R, INPUT);
 
  pinMode(trigPin_M, OUTPUT);
  pinMode(echoPin_M, INPUT);
//  pinMode(Vin,OUTPUT);
}

void loop() 
{ 
  //move_stop();
  //delay(2000);
  //digitalWrite(Vin,HIGH);
 
  dm = dist_m();
  dr = dist_r();
  if(dr<x && dm >x)
  {
    move_forward();
    Serial.println("moving fwd");
  }
  Serial.println(dm);
  Serial.println(dr);
//delay(500);  
  if(dm<=x)   //LEFT Turn at corner
  {
   // move_stop();
    //delay(1000);
    turn_left_hard();
    delay(10);
    dr = dist_r();
    dm = dist_m();
    Serial.println("turning left");
      
    }
    if(dr>x)
    {
     // move_stop();
      //delay(100);
      turn_right_soft();
      //delay(400);
      Serial.println("turning right");
      Serial.println(dr);
      dr = dist_r();
    }
    if(dr<y)
    {
     // move_stop();
      //delay(100);
      turn_left_soft();
      //delay(400);
      Serial.println("turning right");
      Serial.println(dr);
      dr = dist_r();
    } 
}