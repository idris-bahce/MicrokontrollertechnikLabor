/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 1
Datum des LPr-Versuchs: 16/04/2016
TN1: Bahce, Idris, 599518.
TN2: Winkelmann, Aaron, 598866.
Besonderheiten/Anmerkungen: 
**************************************************************************
**************************************************************************/

const int rot = 1;
const int gelb = 2;
const int gruen = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(rot, OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // 6 sekunde rot an:
  digitalWrite(rot, 1);
  delay(6000);
  // 1,5 sekunde rot und gelb an:
  digitalWrite(gelb, 1);
  delay(1500);

  // 4 sekunde grün an und gelb und rot aus:
  digitalWrite(rot, 0);
  digitalWrite(gelb, 0);
  digitalWrite(gruen, 1);
  delay(4000);

  // 1,5 sekunde nur gelb an:
  digitalWrite(rot, 0);
  digitalWrite(gruen, 0);
  digitalWrite(gelb, 1);
  delay(1500);

  //alle aus und loop fängt erneut an:
  digitalWrite(gelb, 0);
}
