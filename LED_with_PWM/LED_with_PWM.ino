const int pin = D2;
const int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  pinMode(potPin, INPUT);
  analogWriteRange(1023);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int potValue = analogRead(potPin);

  analogWrite(pin, potValue);

  delay(10);

}
