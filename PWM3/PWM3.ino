/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 1c
Wie unter (a) ist an Pin D10 eine vorzugsweise gelbe LED und an Pin D11 eine vorzugsweise
rote LED [jeweils mit zugehörigen Vorwiderständen] angeschlossen. Programmieren Sie den
Mikrocontroller derart, dass die gelbe LED hell wird, wenn die rote LED dunkel wird und
umgekehrt. Die Helligkeit steuern sollen Sie in diesem Fall mit einem PotenƟometer, welches
an A1 angeschlossen ist. Bei PoƟ-Rechtsanschlag leuchtet die rote LED mit voller Helligkeit,
bei PoƟ-Linksanschlag leuchtet hingegen die gelbe LED mit voller Helligkeit und die rote
leuchtet nicht. 
**************************************************************************
**************************************************************************/
const int LEDRed = 11; // Rote LED pin als D11
const int LEDGelb = 10; // Gelbe LED pin als D10
const int poti = A1;  // Potentiometer pin als A0

void setup() {
  // put your setup code here, to run once:
  pinMode(poti, INPUT);
  pinMode(LEDRed, OUTPUT);
  pinMode(LEDGelb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogWert = analogRead(poti);
  // Map die 10bits Eingang zu 8bits Ausgang
  int pwm = map(analogWert, 0, 1023, 0, 255);
  // Gib die entsprechende PWM signal 
  analogWrite(LEDRed, pwm);
  analogWrite(LEDGelb, 255-pwm);
}
