/*================ E23 == Sose25/26 ==== LPr-Versuch 03 ==== Aufgabe 3
a) Helligkeitsmesswerte des LDR als ADC-Werte und als Spannungswerte darzustellen,
 Indem sie spaltenweise auf dem seriellem Monitor ausgeben werden,
 Spannungswerte uLDR als Zeitreihe auf dem seriellem PloƩer erscheinen.
b) Eine LED mit Vorwiderstand an D12 bei AbschaƩung des LDR eingeschaltet wird, bei Helligkeit
wieder aus geht.
c) Die Bargraph-Anzeige an D2 bis D11 in Abhängigkeit vom LDR-Helligkeitswert durch µCProgramm angesteuert wird (dunkel: alle LEDs der Bargraph-Anzeige leuchten, miƩlere
Helligkeit: 5 LEDs an D2 bis D6 leuchten, max. Helligkeit: alle LEDs der Bargraph-Anzeige sind
aus) 
**************************************************************************
**************************************************************************/
/* Alte Version
const int LED10 = 11; // LED pin als D11
const int LED9 = 10; // LED pin als D10
const int LED8 = 9; // LED pin als D9
const int LED7 = 8; // LED pin als D8
const int LED6 = 7; // LED pin als D7
const int LED5 = 6; // LED pin als D6
const int LED4 = 5; // LED pin als D5
const int LED3 = 4; // LED pin als D4
const int LED2 = 3; // LED pin als D3
const int LED1 = 2; // LED pin als D2*/

const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //Alle pins zwischen 2-11
const int LED12 = 12; // LED pin als D12
const int LDR = A0;  // Potentiometer pin als A0
int analogWert = 0;
int anzahlLeuchtendeLEDs = 0; // folge anzahl der leuchtenden LEDs

void setup() {
  // put your setup code here, to run once:
  /* Alte Version
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  */
  //Alle pins mit einem Loop bestimmen
  for(int i = 0; i < 10; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(LDR, INPUT);
  pinMode(LED12, OUTPUT);
  // Öffne die serielle Schnittstelle bei 9600 Bit/s
  Serial.begin(9600); 
}

//c) Die erfassten ADC-Werte in Spannungswerte umrechnen 
// 5V / 1023 = 0.00488758553 -> das ist die Auflösung
float spannungsWert(int wert){
  return 5/1023.0 * wert;
}

void loop() {
  // put your main code here, to run repeatedly:

// Lese die analoge Eingang
  analogWert = analogRead(LDR);
  //Finde die Spannung
  float volt = spannungsWert(analogWert);

  // Eine LED mit Vorwiderstand an D12 bei Abschaltung des LDR eingeschaltet wird, bei Helligkeit wieder aus geht. 
  if(analogWert < 500){
    digitalWrite(LED12, 1);
  }else{
    digitalWrite(LED12, 0);
  }

  //Die Bargraph-Anzeige an D2 bis D11 in Abhängigkeit vom LDR-Helligkeitswert durch µCProgramm angesteuert wird
  //Map die Analogwert zum 10
  int barZahl = map(analogWert, 0, 1023, 0, 10);
  //Lass es leuchten mit einem loop
  for(int i = 0; i < 10; i++){
    if(i < barZahl){
      digitalWrite(ledPins[i], 1);
    }else{
      digitalWrite(ledPins[i], 0);
    }
  }

  //print Werte
  Serial.print(analogWert);   
  Serial.print("\t");         
  Serial.println(volt);
  delay(100); // Kurze Pause für eine ruhigere Kurve im Plotter


/* Alte Version
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
  }else if(analogWert >= 102 && analogWert < 204){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 204 && analogWert < 306){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 306 && analogWert < 408){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 0);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 408 && analogWert < 510){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 0);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 510 && analogWert < 612){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 0);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 612 && analogWert < 714){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 0);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 714 && analogWert < 816){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 0);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 816 && analogWert < 918){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 0);
    digitalWrite(LED10, 0);
  }else if(analogWert >= 918 && analogWert < 1000){
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
    digitalWrite(LED4, 1);
    digitalWrite(LED5, 1);
    digitalWrite(LED6, 1);
    digitalWrite(LED7, 1);
    digitalWrite(LED8, 1);
    digitalWrite(LED9, 1);
    digitalWrite(LED10, 0);
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
  }
  */


 
}
