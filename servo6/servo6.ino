/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1e
Programmieren Sie das µC-board nun derart, dass Sie eine beliebige PosiƟon des Servoarms
von 0% (linke Endlage) bis 100% (rechte Endlage) vorgeben können, die PosiƟon angefahren
wird und der Zustand gehalten wird, bis Sie die nächste anzufahrende PosiƟon vorgeben.
(Die PosiƟonsvorgabe soll alternaƟv in % oder in Grad möglich sein.) 
**************************************************************************
**************************************************************************/
#include "Servo.h"  //Class include
Servo myservo;      // Class inizialieren
int degree = 0;     //Winkel des Servos

void verarbeitungInProzent() {
  Serial.println("Wie viel Prozent?");

  // Warten, bis der Nutzer eine Zahl eingibt
  while (Serial.available() == 0) {}

  int prozent = Serial.parseInt();

  // Puffer komplett leeren, um Zeilenumbrüche zu ignorieren
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Rationale Begrenzung: Werte unter 0 werden zu 0, über 100 zu 100
  prozent = constrain(prozent, 0, 100);

  degree = map(prozent, 0, 100, 0, 180);
  myservo.write(degree);

  Serial.print("Position gesetzt auf: ");
  Serial.print(prozent);
  Serial.println("%\n");
}

void verarbeitungInWinkel() {
  Serial.println("Welche Winkel?(Zwischen 0 und 180°)");

  // Warten, bis der Nutzer eine Zahl eingibt
  while (Serial.available() == 0) {}

  int winkel = Serial.parseInt();

  // Puffer komplett leeren, um Zeilenumbrüche zu ignorieren
  while (Serial.available() > 0) {
    Serial.read();
  }

  // Rationale Begrenzung: Werte unter 0 werden zu 0, über 180 zu 180
  winkel = constrain(winkel, 0, 180);

  myservo.write(winkel);

  Serial.print("Position gesetzt auf: ");
  Serial.print(winkel);
  Serial.println("°\n");
}

void setup() {
  myservo.attach(9);   //Servo in pin 9 benutzen
  Serial.begin(9600);  //Serial monitor starten
}

void loop() {
  //Eingabe möglichkeiten geben:
  Serial.println("Wie willst du die Position vorgeben?");
  Serial.println("1: Prozent (%)");
  Serial.println("2: Winkel (°)");

  // Das Programm pausiert hier, bis eine Eingabe erfolgt
  while (Serial.available() == 0) {}

  int choice = Serial.parseInt();

  // Puffer komplett leeren, um Zeilenumbrüche zu ignorieren
  while (Serial.available() > 0) {
    Serial.read();
  }

  switch (choice) {
    case 1:
      verarbeitungInProzent();
      break;
    case 2:
      verarbeitungInWinkel();
      break;
    default:
      Serial.println("Falsche eingabe!");
  }
}
