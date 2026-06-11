/*================ E23 == Sose25/26 ==== LPr-Versuch 05 ==== Aufgabe 1e
Ergänzen Sie Ihren Programmcode dahingehend, dass jetzt zusätzlich die jeweils aktuell auf
dem Digit angezeigte Ziffer und die zugehörige BitkombinaƟon im seriellen Monitor mit
einem vorangestelltem Kurztext zeilenweise ausgeben werden, bspw [vergl. mit Tab. 1] :
Aktuelle Ziffer: 0 Zugehörige Bitkombi: 1111110
Aktuelle Ziffer: 1 Zugehörige Bitkombi: 0110000
…
Aktuelle Ziffer: 9 Zugehörige Bitkombi: 1111011
Aktuelle Ziffer: 0 Zugehörige Bitkombi: 1111110
usw.
Laden Sie den code auf den µC. Testen Sie Ihren Programmiererfolg und speichern Sie Ihre
vollumfänglich kommenƟerte finale Version zu (e) unter IhrNachname_OneDigit01e.txt ab
(alle TN individuell)! 
**************************************************************************
**************************************************************************/
byte pinArray[7] = { 2, 3, 4, 5, 6, 7, 8 };  //pins
//Alle Zusatande in einem 2D Array wie in Tab1 ohne Punkt
byte segmente[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 0, 0, 1 },
  { 0, 1, 1, 0, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0 },
  { 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1 }
};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < sizeof(pinArray) / sizeof(pinArray[0]); i++) {
    pinMode(pinArray[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte row = sizeof(segmente) / sizeof(segmente[0]);
  byte col = sizeof(segmente[0]) / sizeof(segmente[0][0]);
  //Schleife für Zeile
  for (int i = 0; i < row; i++) {
    Serial.print("Aktuelle Ziffer: ");
    Serial.print(i);
    Serial.print("  Zugehörige Bitkombi:");
    //Schleife für Spalte
    for (int j = 0; j < col; j++) {
      digitalWrite(pinArray[j], segmente[i][j]);
      Serial.print(segmente[i][j]);
    }
    Serial.println();
    delay(1000);  //1 sekunde warten
  }
}
