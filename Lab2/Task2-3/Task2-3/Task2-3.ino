const int button = 3;
const int led = 5;
bool buttonState = 0;
bool last = 0;
bool ledState = 0;

const int buttonA = 2;
const int ledA = 6;
volatile bool ledStateA = 0;
volatile unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  pinMode(buttonA, INPUT);
  pinMode(ledA, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonA), buttonISR, FALLING);
}

void buttonISR(){
  unsigned long t = millis();

  if((t - lastDebounceTime) > debounceDelay){
    ledStateA = !ledStateA;
    digitalWrite(ledA, ledStateA);
    
  }
  lastDebounceTime = t;
  
}

void loop() {
  buttonState = digitalRead(button);

  if((last == HIGH && buttonState == LOW)){
    ledState = !ledState;
    digitalWrite(led, ledState);
    
  }
  last = buttonState;

  delay(2000);

}
