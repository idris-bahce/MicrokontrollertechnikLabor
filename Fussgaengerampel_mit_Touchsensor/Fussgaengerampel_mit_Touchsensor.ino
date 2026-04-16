/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 4
Datum des LPr-Versuchs: 16/04/2016
TN1: Bahce, Idris, 599518.
TN2: Winkelmann, Aaron, 598866.
Besonderheiten/Anmerkungen: 
**************************************************************************
**************************************************************************/
//I/O für die Autos
const int rotAuto = 8;
const int gelbAuto = 9;
const int gruenAuto = 10;

//I/O für die füssgänger
const int rotFus = 6;
const int gruenFus = 7;
const int touch = 2;

int touchedSpat = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(rotAuto, OUTPUT);
  pinMode(gelbAuto, OUTPUT);
  pinMode(gruenAuto, OUTPUT);
  pinMode(rotFus, OUTPUT);
  pinMode(gruenFus, OUTPUT);
  pinMode(touch, INPUT);

}

void fussgaenger(){
  //gelb erst 3,5 sekunden für autos
  delay(3500);
  digitalWrite(rotAuto, 0);
  digitalWrite(gelbAuto, 1);
  digitalWrite(gruenAuto, 0);

  //rot nach 1 sekunden für autos
  delay(1500);
  digitalWrite(rotAuto, 1);
  digitalWrite(gelbAuto, 0);
  digitalWrite(gruenAuto, 0);


  //grün für die Fussgänger
  digitalWrite(rotFus, 0);
  digitalWrite(gruenFus, 1);
  delay(5000);

  //rot für die Fussgänger
  digitalWrite(rotFus, 1);
  digitalWrite(gruenFus, 0);
  delay(500); // Halbe sekunde warten bis die Fussgänger auf dem Strase weg gehen

  //Rot und gelb
  digitalWrite(rotAuto, 1);
  digitalWrite(gelbAuto, 1);
  digitalWrite(gruenAuto, 0);
  delay(1500);

}

void fahrer(){

  // grün
  digitalWrite(rotAuto, 0);
  digitalWrite(gelbAuto, 0);
  digitalWrite(gruenAuto, 1);
  // fussgänger rot
  digitalWrite(rotFus, 1);

}

void loop() {
  // put your main code here, to run repeatedly:

  int touchedAktuel = digitalRead(touch);// Es beschützt von der Prellen
  if(touchedAktuel == HIGH && touchedSpat == LOW){
    fussgaenger();
  }
  fahrer();
  touchedSpat = touchedAktuel;
}
