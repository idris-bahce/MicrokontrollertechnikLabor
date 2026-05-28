/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 2c
Programmieren Sie den Mikrocontroller derart, dass Sie über die Konsole jeweils eine von
sieben vordefinierten Farben durch Zifferneingabe vorgeben können, die RGB-LED mit dieser
Farbe leuchtet und gleichzeiƟg auf dem seriellen Monitor die Farbbezeichnung und die von
Ihnen gewählten RGB-Werte in einer Zeile angezeigt werden [vergl. mit Tabelle 1]! 
**************************************************************************
**************************************************************************/
int LEDRot = 3;    //Rote LED D3
int LEDGruen = 5;  //Rote LED D5
int LEDblau = 6;   //Rote LED D6
// PWM Signale von Pins
int pwmRot = 0;
int pwmGruen = 0;
int pwmBlau = 0;

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

  Serial.begin(9600);

  // Eine Begrüßungsnachricht, sobald der Arduino startet
  Serial.println("System gestartet.");
  Serial.println("Bitte geben Sie eine Zahl zwischen 1 und 7 ein, um folgende Farben zu sehen:");
  Serial.println("1: Rot\n2: Gruen\n3: Blau\n4: Cyan\n5: Magenta\n6: Gelb\n7: Weiss");
}

void loop() {

  if (Serial.available() > 0) {

    // Serial.parseInt() liest die ankommenden Zeichenketten und sucht
    // automatisch nach der ersten gültigen ganzen Zahl (Integer).
    int zustaende = Serial.parseInt();

    // Wenn man im Seriellen Monitor "Enter" drückt, wird oft noch
    // ein unsichtbares Zeichen (Newline) gesendet, das parseInt() als 0 liest.
    // Mit dieser if-Abfrage filtert man das heraus.
    if (zustaende > 0 && zustaende <= 7) {
      switch (zustaende) {
        case 1:  //(255, 0, 0) Rot wobei es (R G B) ist
          pwmRot = 255;
          pwmGruen = 0;
          pwmBlau = 0;
          ausgabe = "ROT (R: 255, G: 0, B: 0)";
          break;
        case 2:  //(0, 255, 0) Gruen
          pwmRot = 0;
          pwmGruen = 255;
          pwmBlau = 0;
          ausgabe = "GRUEN (R: 0, G: 255, B: 0)";
          break;
        case 3:  //(0, 0, 255) Blau
          pwmRot = 0;
          pwmGruen = 0;
          pwmBlau = 255;
          ausgabe = "BLAU (R: 0, G: 0, B: 255)";
          break;
        case 4:  //(0, 255, 255) Cyan
          pwmRot = 0;
          pwmGruen = 255;
          pwmBlau = 255;
          ausgabe = "CYAN (R: 0, G: 255, B: 255)";
          break;
        case 5:  //(255, 0, 255) Magenda
          pwmRot = 255;
          pwmGruen = 0;
          pwmBlau = 255;
          ausgabe = "MAGENTA (R: 255, G: 0, B: 255)";
          break;
        case 6:  //(255, 255, 0) Gelb
          pwmRot = 255;
          pwmGruen = 255;
          pwmBlau = 0;
          ausgabe = "GELB (R: 255, G: 255, B: 0)";
          break;
        case 7:  //(255, 255, 255) Weiss
          pwmRot = 255;
          pwmGruen = 255;
          pwmBlau = 255;
          ausgabe = "WEISS (R: 255, G: 255, B: 255)";
          break;
      }

      // print() schreibt den Text
      Serial.print("Farbzeichnung: ");
      Serial.println(ausgabe);

    } else if (zustaende != 0) {
      // Springt nur hier rein, wenn die Zahl z.B. 8, 9 oder groesser ist.
      // Die 0 (verursacht durch das Enter-Zeichen) wird ignoriert und die LED bleibt an.
      Serial.println("Ungueltige Eingabe -> AUS");
      pwmRot = 0;
      pwmGruen = 0;
      pwmBlau = 0;
    }
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
}
