/*================ E23 == Sose25/26 ==== LPr-Versuch 06 ==== Aufgabe 1d
Ordnen Sie drei Taster auf dem Breadboard mit hinreichendem/ mindestens fingerbreitem
Abstand nebeneinander an und programmieren Sie das µC-board nun so, dass der Servoarm
bei Drücken der linken Taste in die ca. 0°-PosiƟon (linke Endlage), bei Drücken der miƩleren
Taste in die 90°-PosiƟon und bei Drücken der rechten Taste in die ca. 180°-PosiƟon (rechte
Endlage) fährt! 
**************************************************************************
**************************************************************************/
#include <Servo.h>  //servo lib importieren
Servo myservo;      //Class inizialieren
int grad0 = 2;
int grad90 = 4;
int grad180 = 6;
//Prellen Massnahmen
unsigned long delay_time = 80;  //80ms
unsigned long lastdebounce_time_taster1 = 0;
unsigned long lastdebounce_time_taster2 = 0;
unsigned long lastdebounce_time_taster3 = 0;


void setup() {
  myservo.attach(9);        //servo zu pin 9 zuweisen
  pinMode(grad0, INPUT);    //0 Grad taster
  pinMode(grad90, INPUT);   //90 Grad taster
  pinMode(grad180, INPUT);  //180 Grad taster
}

void loop() {
  // Da ich alle gleichzeitig drei gedruckte Taster vermeiden will, benutze ich else if:
  if (digitalRead(grad0) == 1 && (millis() - lastdebounce_time_taster1 >= delay_time)) {
    lastdebounce_time_taster1 = millis();
    myservo.write(0);
  } else if (digitalRead(grad90) == 1 && (millis() - lastdebounce_time_taster2 >= delay_time)) {
    lastdebounce_time_taster2 = millis();
    myservo.write(90);
  } else if (digitalRead(grad180) == 1 && (millis() - lastdebounce_time_taster3 >= delay_time)) {
    lastdebounce_time_taster3 = millis();
    myservo.write(180);
  }
}
