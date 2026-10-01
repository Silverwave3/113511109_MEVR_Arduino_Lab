#include <TimerOne.h>
volatile int timercount = 0;
const int buttonA = 10;
const int buttonB = 11;
const int LEDA = 2;
const int LEDB = 3;
volatile int A = 0;
int B = 0;

void timer_int(){
  ++timercount;
  A = digitalRead(buttonA);
  Serial.println(A);

  if(A == 0){
    digitalWrite(LEDA, LOW);
  }
  else{
    digitalWrite(LEDA, HIGH);
  }
}


void setup() {
  Serial.begin(9600);
  Timer1.initialize(50000);
  Timer1.attachInterrupt(timer_int);
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);

}

void loop() {
  Serial.println(timercount);

  B = digitalRead(buttonB);
  //Serial.println(B);
  if(B == 0){
    digitalWrite(LEDB, LOW);
  }
  else{
    digitalWrite(LEDB, HIGH);
  }

  delay(1000);
}
