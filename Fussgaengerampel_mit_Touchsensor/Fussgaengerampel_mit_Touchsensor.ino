/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 4
Aufgabe 4: Fußgängerampel mit Touchsensor
 5 LEDs (2*rot, 2*grün, 1*gelb) mit Vorwiderständen
 1 Touchsensor
Wenden Sie Ihr Erlerntes aus den Aufgaben 2 und 3 systemaƟsch an und realisieren Sie nun eine
erweiterte Ampellösung für Fahrzeuge und Fußgänger.
Mit drei LEDs (rot, gelb und grün) und den jeweiligen Vorwiderständen soll auf einem breadboard
eine Ampel für die Fahrbahn realisiert werden und mit zwei weiteren LEDs (rot, grün) eine Ampel für
Fußgänger. Fußgänger sollen durch BetäƟgen eines Touchsensors die Grünphase für Fußgänger
anfordern können.
Die Wartezeit für Fußgänger nach der TouchsensorbetäƟgung soll 5 s betragen, Fahrbahnnutzer
erhalten entsprechend Abb. 2 innerhalb dieser 5 s erst Gelb dann Rot.
Nach einer definierten Zeitdauer von 10 Sekunden schaltet die Ampel für Fußgänger wieder auf Rot
und die Fahrbahnampel über Rot/Gelb auf Grün (vergl. mit Abb. 2).
a) Stecken Sie möglichst strukturiert eine geeignete Schaltung auf dem breadboard! Vergessen
Sie die LED-Vorwiderstände nicht (a´ 220…470 ! Empfohlen werden drei 5 mm LEDs für die
Fahrbahnampel und zwei 3 mm LEDs für die Fußgängerampel.
b) Den Touchsensor schließen Sie wie gehabt an:
 GND vom Touchsensor an GND vom µC-board
 Vcc vom Touchsensor an 5 V vom µC-board
 I/O vom Touchsensor an D2 vom µC-board
c) Skizzieren Sie sich den zeitlichen Ablauf des Hauptprogramms (Erweiterung zu Abb.2) in
einem Diagramm.
d) Schreiben Sie vollumfänglich kommenƟerten Programmcode zur Lösung der Aufgabe.
e) Laden Sie das Programm auf den µC und testen Sie die FunkƟonsfähigkeit Ihres Programms!
f) Speichern Sie die finale Version Ihres Codes – zwingend mit Kommentarheaderblock – als
g) Datei mit der Endung .txt, so dass es mit einem beliebigen Editor gelesen werden kann (kein
*.ino, keine pdf o.ä.) 
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
