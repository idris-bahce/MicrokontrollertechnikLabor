/*================ E23 == Sose25/26 ==== LPr-Versuch 05 ==== Aufgabe 1d
Schreiben Sie unter Nutzung eines zweidimensionalen Arrays und verschachtelter forSchleifen einen Programmcode, der bewirkt, dass auf dem Siebensegment-Digit die Ziffern
von 0 bis 9 in aufsteigender Reihenfolge mit einem zeitlichen Abstand von jeweils 1 Sekunde
angezeigt werden.
Laden Sie den code zu auf den µC. Testen Sie Ihren Programmiererfolg und speichern Sie Ihre
vollumfänglich kommenƟerte11 finale Version zu (d) unter IhrNachname_OneDigit01d.txt ab
(alle TN individuell12)! 
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
}

void loop() {
  // put your main code here, to run repeatedly:
  byte row = sizeof(segmente) / sizeof(segmente[0]);
  byte col = sizeof(segmente[0]) / sizeof(segmente[0][0]);
  //Schleife für Zeile
  for (int i = 0; i < row; i++) {
    //Schleife für Spalte
    for (int j = 0; j < col; j++) {
      digitalWrite(pinArray[j], segmente[i][j]);
    }
    delay(1000);//1 sekunde warten
  }
}
