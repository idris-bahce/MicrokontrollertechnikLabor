/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 2b
Realisieren Sie unter Nutzung des SteckbreƩs (breadbord) folgende Schaltung:
 Rote LED mit Vorwiderstand an D3,
 Grüne LED mit Vorwiderstand an D5,
 Blaue LED mit Vorwiderstand an D6,
 Common Anode an +5 V bzw. Common Cathode an GND.
Beachten Sie, dass in Abh. davon die RGB-chips HIGH- o. LOW-akƟv reagieren und
entsprechend anzusteuern sind.
Hinweis: Sinnvoll ist es, im Programm eine einfache WahlopƟon für beide Fälle vorzusehen. 
**************************************************************************
**************************************************************************/
int LEDRot = 3;    //Rote LED D3
int LEDGruen = 5;  //Rote LED D5
int LEDblau = 6;   //Rote LED D6
// PWM Signale von Pins
int pwmRot = 255;  // da ich von oben Spitze der Palette anfange
int pwmGruen = 0;
int pwmBlau = 0;

int zustaende = 0;

//Gemeinsame Anode oder Kathode
//ACHTUNG: Wenn es um eine common Anode geht, bitte machen sie isCommonCathode = false;
bool isCommonCathode = true;


unsigned long startTime = millis();
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDRot, OUTPUT);
  pinMode(LEDGruen, OUTPUT);
  pinMode(LEDblau, OUTPUT);
}

void loop() {
  // Jedes 1 Sekunde sollen die ausgang von 0 auf 255 laufen, was die 8bit ausgang entspricht
  // in einer Sekunde 1000ms -> 1000ms / 256 = ungefähr 4ms
  if (millis() - startTime >= 4) {
    startTime = millis();
    switch (zustaende) {
      case 0:  //(255, nachOben, 0) wobei es (R G B) ist
        pwmGruen++;
        if (pwmGruen >= 255) zustaende++;  //Nächste case
        break;
      case 1:  //(nachUnten, 255, 0)
        pwmRot--;
        if (pwmRot <= 0) zustaende++;  //Nächste case
        break;
      case 2:  //(0, 255, nachOben)
        pwmBlau++;
        if (pwmBlau >= 255) zustaende++;  //Nächste case
        break;
      case 3:  //(0, nachUnten, 255)
        pwmGruen--;
        if (pwmGruen <= 0) zustaende++;  //Nächste case
        break;
      case 4:  //(nachOben, 0, 255)
        pwmRot++;
        if (pwmRot >= 255) zustaende++;  //Nächste case
        break;
      case 5:  //(255, 0, nachUnten)
        pwmBlau--;
        if (pwmBlau <= 0) zustaende = 0;  //Anfang Case
        break;
    }

    // HARDWARE-ANPASSUNG: Wahloption verarbeiten
    // Lokale Variablen für die finale Ausgabe
    // Wenn wir das nicht machen würden, dann würde ein fall von Anode logik wurde zerstört
    int outRot = pwmRot;
    int outGruen = pwmGruen;
    int outBlau = pwmBlau;

    // Wenn es sich um eine gemeinsame Anode handelt, müssen die Signale 
    // invertiert werden (0 wird zu 255, 255 wird zu 0).
    if (!isCommonCathode) { 
      outRot = 255 - pwmRot;
      outGruen = 255 - pwmGruen;
      outBlau = 255 - pwmBlau;
    }
    analogWrite(LEDRot, outRot);
    analogWrite(LEDGruen, outGruen);
    analogWrite(LEDblau, outBlau);
  }
}
