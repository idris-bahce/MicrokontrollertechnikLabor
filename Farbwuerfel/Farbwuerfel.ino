/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 2d
Programmieren Sie den Mikrocontroller derart, dass er als Farbwürfel fungiert. D.h. auf ein
Event (Konsolenwerteingabe, Sensorschwellwertüberschreitung, Tastendruck o.ä.) soll ein
zufälliger Wert zwischen 1…6 gewürfelt werden und selbiger einerseits als vorgegebene LEDFarbe leuchten [vergl. mit Tabelle 2 bzw. 3] und andererseits sollen gewürfelter Wert und
zugehörige Leuchƞarbe auf dem seriellen Monitor ausgegeben werden bis erneut gewürfelt
wird – wiederum ausgelöst durch ein Event (s.o.)! 
**************************************************************************
**************************************************************************/
int LEDRot = 3;    //Rote LED D3
int LEDGruen = 5;  //Grüne LED D5
int LEDblau = 6;   //Blaue LED D6
// PWM Signale von Pins
int pwmRot = 0;
int pwmGruen = 0;
int pwmBlau = 0;
// Digitales Input mit Taster für den Würfel Wurf
// Achtung: Es ist einen Pull Down Taster
int taster = 2;

//Schreib die Anfang Zeit
unsigned long startTime = millis();
//Prellen Zeit 150ms
int prellen = 150;

//Ausgabe
String ausgabe = "";


//Gemeinsame Anode oder Kathode
//ACHTUNG: Wenn es um eine common Anode handelt, bitte machen sie isCommonCathode = false;
bool isCommonCathode = true;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDRot, OUTPUT);
  pinMode(LEDGruen, OUTPUT);
  pinMode(LEDblau, OUTPUT);
  pinMode(taster, INPUT);

  Serial.begin(9600);
  //Durch das Rauschen an den pin A0 wird die zufällige Zählen generiert
  randomSeed(analogRead(A0));
}

void loop() {
  //Generiert ganze Zahl von 1 bis 6
  if (millis() - startTime >= prellen && digitalRead(taster) == HIGH) {
    startTime = millis();
    int zahl = random(1, 7);
    //Switch case für den Würfel
    switch (zahl) {
      case 1:  //(255, 255, 0) Gelb
        pwmRot = 255;
        pwmGruen = 255;
        pwmBlau = 0;
        ausgabe = "GELB (R: 255, G: 255, B: 0)";
        break;
      case 2:  //(0, 255, 0) Gruen
        pwmRot = 0;
        pwmGruen = 255;
        pwmBlau = 0;
        ausgabe = "GRUEN (R: 0, G: 255, B: 0)";
        break;
      case 3:  //(255, 0, 0) Rot wobei es (R G B) ist
        pwmRot = 255;
        pwmGruen = 0;
        pwmBlau = 0;
        ausgabe = "ROT (R: 255, G: 0, B: 0)";
        break;
      case 4:  //(0, 0, 255) Blau
        pwmRot = 0;
        pwmGruen = 0;
        pwmBlau = 255;
        ausgabe = "BLAU (R: 0, G: 0, B: 255)";
        break;
      case 5:  //(0, 255, 255) Cyan
        pwmRot = 0;
        pwmGruen = 255;
        pwmBlau = 255;
        ausgabe = "CYAN (R: 0, G: 255, B: 255)";
        break;
      case 6:  //(255, 0, 255) Magenda
        pwmRot = 255;
        pwmGruen = 0;
        pwmBlau = 255;
        ausgabe = "MAGENTA (R: 255, G: 0, B: 255)";
        break;
    }


    // HARDWARE-ANPASSUNG: Wahloption verarbeiten
    // Lokale Variablen für die finale Ausgabe
    // Diese Abteil wurde vorheriegen Aufgabe coppiert
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
    Serial.println(ausgabe);
  }
}