//red
bool buttonState = 0;
int last = 0;
const int button = 2;
const int R = 12;
int red = 1;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

//green
int green = 255;
const int G = 10;

//blue
int blue = 0;
const int resistor = A2;
const int B = 11;

void setup() {
  //red
  pinMode(button, INPUT);
  pinMode(R, OUTPUT);
  digitalWrite(R, red);

  //green
  Serial.begin(9600);
  pinMode(G, OUTPUT);
  Serial.println("Green Light Brightness Controller");
  analogWrite(G, green);
  
  //blue
  pinMode(resistor, INPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  //red
  int reading = digitalRead(button);
  if (reading != last) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        red = !red;
        digitalWrite(R, red);
      }
    }
  }

  last = reading;

  //green
  while(Serial.available() > 0){
    green = Serial.parseInt();
    Serial.print("Green Light Brightness: ");
    Serial.println(green);
    analogWrite(G, 255 - green);
  }

  //blue
  blue = analogRead(resistor);
  analogWrite(B, blue/4);
}
