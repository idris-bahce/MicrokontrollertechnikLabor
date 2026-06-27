/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1b
Programmieren das µC-board nun mit Verwendung der library servo.h. derarƟg, dass Sie die
Servo-PosiƟon mit einem PotenƟometer einstellen können. Die Drehrichtung des
PotenƟometereinstellers soll dabei der Drehrichtung des Servo-Arms entsprechen
(Linksdrehung bewirkt Linksdrehung, Rechtsdrehung bewirkt Rechtsdrehung, PoƟ in
MiƩelstellung  Servo-Arm zeigt auf 90°-PosiƟon). 
**************************************************************************
**************************************************************************/
#include <Servo.h> //servo lib importieren
int potInput = A0; //analog Input von Potentiometer
Servo myservo; //Class inizialieren


void setup() {
  myservo.attach(9); //servo zu pin 9 zuweisen
}

void loop() {
  int analogInput = analogRead(potInput); //lese die Analoge Signale durch Pin A0
  int degre = map(analogInput, 0, 1023, 0, 180); //Map die Value, die aus A0 stammen und konvertiert ihr zwischen 0 und 180 Grad
  myservo.write(degre); //Gib die Value zu Servo Motor
}
