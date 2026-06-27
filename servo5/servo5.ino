/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1d
Programmieren das µC-board nun als „quasi Scheibenwischer“, der von Ihnen mit einem
Taster immer wieder beliebig an oder ausgeschaltet werden kann, nach dem Ausschalten
fährt der Servoarm in die rechte Endlage. 
**************************************************************************
**************************************************************************/
#include "Servo.h" // Bibliothek 
Servo myservo; //Class inizialisieren
const int button = 2; //button
unsigned long delay_time = 200;  // 200ms
unsigned long last_bounce_time = 0; //anstatt delay zu benutzen folgen wir die Zeit indem es gedruckt wird
bool state = false; // Zustand für an- und ausschalten

int deg = 0; // Winkel der Servo. 0 ist Anfang Position
bool inc_dec_flag = true; //Ein Folger Flag um zwischen increase und decrease gewährleisten

unsigned long last_movement_time = 0; // Da die Servo selbst Takt der Code nicht folgen kann, 3ms Warte zeit zwischen jeder Schritt
unsigned long delay_time_servo = 3;  // 3ms

// Incrementiert die Winkel
void deg_increment() {
  last_movement_time = millis();
  myservo.write(deg++);
  if (deg >= 180) {
    inc_dec_flag = false;
  }
}

// Decrementiert die Winkel
void deg_decrement() {
  last_movement_time = millis();
  myservo.write(deg--);
  if (deg <= 0) {
    inc_dec_flag = true;
  }
}

void setup() {
  myservo.attach(9); //Benutzt pin 9 für Servo
  pinMode(button, INPUT); //Input mode für Taster
}

void loop() {
  // Wenn button gedruckt, wird die Zustand entweder an oder aus
  if (digitalRead(button) == 1 && (millis() - last_bounce_time >= delay_time)) {
    last_bounce_time = millis();
    state = !state;
  }

  // Wenn die State von an zu aus geschaltet wird, wird es nicht ausgeschaltet, bis die Winkel Null ist 
  if (state || deg != 0) {
    if ((inc_dec_flag) && (millis() - last_movement_time >= delay_time_servo)) {
      deg_increment();
    }
    if ((!inc_dec_flag) && (millis() - last_movement_time >= delay_time_servo)) {
      deg_decrement();
    }
  }
}
