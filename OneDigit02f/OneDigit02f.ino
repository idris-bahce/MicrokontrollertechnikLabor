/*================ E23 == Sose25/26 ==== LPr-Versuch 05 ==== Aufgabe 1f
Jetzt sind Sie aufgefordert die gleiche ProgrammfunkƟonalität unter Verwendung eines
eindimensionalen Arrays zu bewirken.
 Dazu müssen Sie – unter Beachtung der entsprechenden Syntax – den relevanten
Inhalt aus dem zweidimensionalen Array in ein eindimensionales Array transferieren.
Die Segmente die für die Ziffern anzusteuern sind, werden als BitkombinaƟon im
eindimensionalen Array in Bytes binärcodiert abgelegt, gekennzeichnet durch ein
vorangestelltes B:
z.B. B01111110 für 0, B00110000 für 1 usw. [vergl. mit Tab. 1].
[Hinweis: Es werden ohne Dot notwendigerweise nur 7 Bits zur Ansteuerung benöƟgt, daraus erklärt sich die 0 für
das MSB.]
 Ferner muss die for-Schleife zum Abfragen der Bits, zugehörig zu einer ausgewählten
Ziffer, angepasst werden.
 Nutzen Sie die bitRead()-FunkƟon zur Abfrage einzelner Bits in einem Byte und setzen
Sie in Abhängigkeit vom Rückgabewert dieser FunkƟon einzelne Segmente auf HIGH
oder LOW.
Laden Sie Ihren Code auf den µC und testen Sie Ihre Lösung! Speichern Sie Ihre finale Version
zu (f) zur späteren Verwendung ab unter: IhrNachname_OneDigit02f.txt (alle TN individuell)! 
**************************************************************************
**************************************************************************/
const byte lengtPinArray = 7;
const byte lengtSegmente = 10;
byte pinArray[lengtPinArray] = { 2, 3, 4, 5, 6, 7, 8 };  //pins
byte segmente[lengtSegmente] = {
  B01111110, // Ziffer 0 
  B00110000, // Ziffer 1 
  B01101101, // Ziffer 2 
  B01111001, // Ziffer 3 
  B00110011, // Ziffer 4 
  B01011011, // Ziffer 5 
  B01011111, // Ziffer 6 
  B01110000, // Ziffer 7 
  B01111111, // Ziffer 8 
  B01111011  // Ziffer 9 
};
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < lengtPinArray; i++){
    pinMode(pinArray[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  //For schleife für die Zeile
  for(int i = 0; i < lengtSegmente; i++){
    //For schleife für jeden Spalte in Array
    for(int j = 0; j < lengtPinArray; j++){
      byte zustand = bitRead(segmente[i], 6 - j); //Da es ganz von links die bits read, machen wir ein Trick von exakt punkt anzufangen
      digitalWrite(pinArray[j], zustand);
    }
    delay(1000); // 1 Sekunde warten
  }

}
