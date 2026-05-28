/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 1b
Steuern Sie die Helligkeit der roten LED an D11 über einen LDR-Sensor3
 am
Analogeingangspin A0 an [vergl. mit Abbildung 1]. Bei AbschaƩung soll die LED an D11
konƟnuierlich mit zunehmender Dunkelheit heller werden, bei Belichtung soll diese LED
konƟnuierlich dunkler werden.
Es soll im Unterschied zu einer ähnlichen Aufgabe bei einem vorangegangenen LPr-Versuch
kein schwellwertabhängiges an- und ausschalten der LED erfolgen. 
**************************************************************************
**************************************************************************/
const int LED = 11; // LED pin als D11
const int LDR = A0;  // LDR pin als A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogWert = analogRead(LDR);
  // Map die 10bits Eingang zu 8bits Ausgang
  int pwm = map(analogWert, 0, 1023, 255, 0);
  // Gib die entsprechende PWM signal lau die Lichtstärke
  analogWrite(LED, pwm);
}
