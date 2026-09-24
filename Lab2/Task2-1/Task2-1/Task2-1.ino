const int PIN_1A = 9;
const int PIN_2A = 10;
const int var = A0;
int speed = 0;

int value = 0;

void setup() {
  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_2A, OUTPUT);
  pinMode(var, INPUT);
}

void loop() {
  value = analogRead(var);

  if(value > 520){
    speed = map(value, 520, 1023, 0, 255);
    analogWrite(PIN_1A, speed);
    digitalWrite(PIN_2A, LOW);
  }
  else if(value < 500){
    speed = map(value, 500, 0, 0, 255);
    analogWrite(PIN_2A, speed);
    digitalWrite(PIN_1A, LOW);
  }
  else{
    speed = 0;
    analogWrite(PIN_2A, speed);
    digitalWrite(PIN_1A, LOW);
  }
}
