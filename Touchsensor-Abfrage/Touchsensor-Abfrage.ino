/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 3
Aufgabe 3: Touchsensor-Abfrage 
 1 LED mit Vorwiderstand
 1 Touchsensor
In Abhängigkeit von BerührungsakƟvitäten an einem kapaziƟven Touchsensor soll eine LED mit der
ersten Berührung angeschaltet werden, mit der zweiten Berührung ausgeschaltet werden und so fort.
Wird der Touchsensor nicht betäƟgt, soll die LED im jeweils letzten Zustand verharren.
Ihr code muss feststellen ob die LED gerade an- oder ausgeschaltet ist. Empfohlen wird diesbezüglich
eine Variable vom Typ bool zu definieren und zu nutzen.
a) Stecken Sie möglichst strukturiert eine geeignete Schaltung auf dem breadboard! Vergessen Sie
den LED-Vorwiderstand nicht (a´ 220…470 ! 
 GND vom Touchsensor an GND vom µC-board
 Vcc vom Touchsensor an 5 V vom µC-board
 I/O vom Touchsensor an D2 vom µC-board
b) Schreiben Sie vollumfänglich kommenƟerten Programmcode zur Lösung der Aufgabe.
c) Laden Sie das Programm auf den µC und testen Sie die FunkƟonsfähigkeit Ihres Programms!
d) Speichern Sie die finale Version Ihres Codes – zwingend mit Kommentarheaderblock – als
Datei mit der Endung .txt, so dass es mit einem beliebigen Editor gelesen werden kann (kein
*.ino, keine pdf o.ä.) 
**************************************************************************
**************************************************************************/

int touch = 2;
const int led = 7;
bool LEDzustand = false;
int touchedSpaeter = LOW; // es wurde letztes mal nichts gedrückt


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(touch, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

// when die Signal aus touchsensor kommt, ändert die zustand des LEDs:
  int touchedAktuel = digitalRead(touch);

  if(touchedAktuel == HIGH && touchedSpaeter == LOW){ // When man sein hand auf dem sensor halten bleibt, wurde diese if nicht durchgeführt.
    digitalWrite(led, LEDzustand);
    LEDzustand = !LEDzustand;
  }

  touchedSpaeter = touchedAktuel;
}
