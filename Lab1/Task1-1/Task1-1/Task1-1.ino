const int resistor = A2;
const int led = 9;
int value = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(resistor, INPUT);
  Serial.begin(9600);

}

void loop() {
  for(int i = 0; i < 100; ++i){
    value = analogRead(resistor);
    analogWrite(led, round(value/4));
    delay(10);
  }
  Serial.print("Data is ");
  Serial.println(value/4);
}
