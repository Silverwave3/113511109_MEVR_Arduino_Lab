#include <Servo.h>
Servo mine;
int data = 0;
const int echo = 10;
const int trig = 11;
int count = 0;

void setup(){
  mine.attach(9);
  mine.write(0);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  count = pulseIn(echo, HIGH);
  if (count > 0){
    data = 0.11 * count;
    if(data < 180){
      mine.write(data);
    }

  }
  
  delay(100);
}
