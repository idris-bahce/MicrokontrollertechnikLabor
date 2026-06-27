/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1a
a) Programmieren das µC-board nun mit Verwendung der library servo.h mit ähnlicher
FunkƟonalität wie unter (a); Kurze Pausen (z.B. 0,5 s) bei den 30°-SchriƩen, längeres
Verharren (ca. 5 s) jeweils in der 0°, 90° u. 180° PosiƟon.
Dazu müssen Sie zunächst mit Steuerbefehlen experimentell den AkƟonsradius testen
(das unterscheidet sich bei einzelnen Servos), dann den Servoarm (quasi als Zeiger)
locker aufstecken – ACHTUNG: keinesfalls per Hand mit Fingern oder anderweiƟg
mechanisch drehen (weder die Servoachse noch den Servoarm o. dgl.) – 
**************************************************************************
**************************************************************************/

#include <Servo.h> //servo lib importieren

Servo myservo;  //Class inizialieren

int degree = 0;  //degree als 0 Grad starten

void setup() {
  myservo.attach(9);  //Servo Steuerungspin zuweisen
}

void loop() {
  
  // Vorwärtsbewegung: 0° bis 180°
  for (degree = 0; degree <= 180; degree += 30) {
    myservo.write(degree); // Bewegen
    
    // Warten
    if(degree == 0 || degree == 90 || degree == 180){
      delay(5000); //5 sekunde warten
    } else {
      delay(500); //0,5 sekunde warten
    }
  }
  
  // Rückwärtsbewegung: 150° bis 30° 
  // (180° und 0° wurden/werden in der Vorwärtsschleife schon abgedeckt)
  for (degree = 150; degree > 0; degree -= 30) {
    myservo.write(degree); // Bewegen
    
    // Warten:
    if(degree == 90){
      delay(5000);
    } else {
      delay(500);
    }
  }
}
