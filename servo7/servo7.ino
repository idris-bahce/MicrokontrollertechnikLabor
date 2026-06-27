/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1f
Programmieren Sie das µC-board nun derart, dass Sie eine Messgröße (z.B. Helligkeit oder
Temperatur erfassen) und den Messwert auf einer selbst geferƟgten Skale mit dem ServoZeigerarm zur Anzeige bringen oder bauen Sie einen LichƩracker (Quasi-Solartracker), der
dem Licht Ihrer Smartphone-Taschenlampe folgt
**************************************************************************
**************************************************************************/
#include "Servo.h"      //Class include
Servo myservo;          // Class inizialieren
const int links = A0;   // Fotosensor am Links
const int rechts = A1;  // Fotosensor am Rechts
int degree = 90;        // Startposition in der Mitte
int toleranz = 40;      // Erst ab einer Differenz von 40 Punkten reagiert das System
int schrittweite = 1;   // Um wie viel Grad sich der Servo pro Zyklus bewegt

void setup() {
  myservo.attach(9);
  myservo.write(degree);  //Mittig starten
  pinMode(links, INPUT);
  pinMode(rechts, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Links: ");
  Serial.println(analogRead(links));
  Serial.print("Rechts: ");
  Serial.println(analogRead(rechts));
  int linkeWert = analogRead(links);
  int rechteWert = analogRead(rechts);

  int diff = abs(rechteWert - linkeWert);

  if (diff > toleranz) {
    if (rechteWert > linkeWert) {
      degree -= schrittweite; // Richtung anpassen, falls er vom Licht wegfährt
    } else if (linkeWert > rechteWert) {
      degree += schrittweite;
    }
  }

  //Grenzen einhalten und Position schreiben
  degree = constrain(degree, 0, 180);
  myservo.write(degree);

  // System abbremsen für mechanische Stabilität
  delay(20);
}
