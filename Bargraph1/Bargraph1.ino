/*================ E23 == Sose25/26 ==== LPr-Versuch 03 ==== Aufgabe 2
Was Sie mit dem code leisten sollen:
 Die 10 LEDs werden in Abhängigkeit von der PotenƟometer-Einstellung, bei voller
Ausnutzung des Einstellbereiches (lineare Übersetzung, d.h. bei einem PoƟExtremum leuchtet keine LED, beim anderen Extremum leuchten alle 10 LEDs, in
MiƩelstellung leuchten 5 von 10 LEDs etc.) angesteuert.
 Den eingelesenen ADC-PotenƟometerwert rechnen Sie in einen Spannungswert um.
 Über den seriellen Monitor geben Sie jeweils in einer Zeile aus:
ADC-Wert: … Spannungswert: … in V Anzahl der leuchtenden LEDs: … 
**************************************************************************
**************************************************************************/

const int LED10 = 11; // LED pin als D11
const int LED9 = 10; // LED pin als D10
const int LED8 = 9; // LED pin als D9
const int LED7 = 8; // LED pin als D8
const int LED6 = 7; // LED pin als D7
const int LED5 = 6; // LED pin als D6
const int LED4 = 5; // LED pin als D5
const int LED3 = 4; // LED pin als D4
const int LED2 = 3; // LED pin als D3
const int LED1 = 2; // LED pin als D2
const int potPin = A0;  // Potentiometer pin als A0
int analogWert = 0;
int anzahlLeuchtendeLEDs = 0; // folge anzahl der leuchtenden LEDs

void setup() {
  // put your setup code here, to run once:
  digitalWrite(LED1, OUTPUT);
  digitalWrite(LED2, OUTPUT);
  digitalWrite(LED3, OUTPUT);
  digitalWrite(LED4, OUTPUT);
  digitalWrite(LED5, OUTPUT);
  digitalWrite(LED6, OUTPUT);
  digitalWrite(LED7, OUTPUT);
  digitalWrite(LED8, OUTPUT);
  digitalWrite(LED9, OUTPUT);
  digitalWrite(LED10, OUTPUT);
  digitalWrite(potPin, INPUT);
  // Öffne die serielle Schnittstelle bei 9600 Bit/s
  Serial.begin(9600); 
}

//c) Die erfassten ADC-Werte in Spannungswerte umrechnen 
// 5V / 1023 = 0.00488758553 -> das ist die Auflösung
float spannungsWert(int wert){
  return (5/1023.0) * wert;
}

void loop() {
  // put your main code here, to run repeatedly:

// Lese die analoge Eingang
  analogWert = analogRead(potPin);

// Entsprechend leuchtet die LEDs -> 1023 wurde 10 LEDs geteilt, jede if else haben 102 abstand
  if(analogWert <= 102){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
    anzahlLeuchtendeLEDs = 1;
  }else if(analogWert >= 102 && analogWert < 204){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 2;
  }else if(analogWert >= 204 && analogWert < 306){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 3;
  }else if(analogWert >= 306 && analogWert < 408){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 4;
  }else if(analogWert >= 408 && analogWert < 510){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 5;
  }else if(analogWert >= 510 && analogWert < 612){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 6;
  }else if(analogWert >= 612 && analogWert < 714){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 7;
  }else if(analogWert >= 714 && analogWert < 816){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 8;
  }else if(analogWert >= 816 && analogWert < 918){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 9;
  }else if(analogWert >= 918 && analogWert < 1020){
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 9;
  }else{
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 1);
    anzahlLeuchtendeLEDs = 10;
  }
  float volt = spannungsWert(analogWert);

  char buffer [80];



  Serial.print("ADC-Wert: ");
  Serial.print(analogWert, DEC);
  Serial.print(" Spannungswert: ");
  Serial.print(volt, DEC);
  Serial.print(" in V Anzahl der leuchtenden LEDs: ");
  Serial.print(anzahlLeuchtendeLEDs, DEC);
  Serial.print("\n");
}
