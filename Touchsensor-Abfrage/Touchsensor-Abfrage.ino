/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 3
Datum des LPr-Versuchs: 16/04/2016
TN1: Bahce, Idris, 599518.
TN2: Winkelmann, Aaron, 598866.
Besonderheiten/Anmerkungen: 
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
