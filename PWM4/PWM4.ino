/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 1d
 ZUSATZ (BiƩe nur und erst bearbeiten, wenn die Aufgaben zur RGB-LED-Farbsteuerung
vollständig und erfolgreich bearbeitet wurden – die Aufgabe 2 ist wichƟger!):
 Eine weitere rote LED (mit Vorwiderstand an D8) und eine weitere gelbe LED
 (mit Vorwiderstand an D12) sollen in Abhängigkeit von der PotenƟometereinstellung blinken:
- Schnelles Blinken wenn gleichfarbige LED hell;
- Langsames Blinken bzw. aus, ,wenn gleichfarbige LED dunkel. 
**************************************************************************
**************************************************************************/
const int LEDRed = 11;     // Rote LED pin als D11 pwm
const int LEDYellow = 10;  // Gelbe LED pin als D10 pwm
const int poti = A1;       // Potentiometer pin als A1
//LEDs zu blinken
const int LEDRot = 8;    // Rote LED pin als D8
const int LEDGelb = 12;  // Gelbe LED pin als D12
unsigned long startTimeRot = millis();
unsigned long startTimeGelb = millis();
bool zustandRot = HIGH;
bool zustandGelb = HIGH;


void setup() {
  // put your setup code here, to run once:
  pinMode(poti, INPUT);
  pinMode(LEDRed, OUTPUT);
  pinMode(LEDYellow, OUTPUT);
  pinMode(LEDRot, OUTPUT);
  pinMode(LEDGelb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogWert = analogRead(poti);
  /* Map die 10bits Eingang zu 8bits Ausgang
  int pwm = map(analogWert, 0, 1023, 0, 255);
  Das war alte Code zu 10bit auf 8bit zubringen. Ich habe KI leistungsfähigere Code gefragt und er hat bit shifting vorgeschlagt.
  Da die Arduino nicht so stärke Rechnung Leistung hat, dauert die map Funktion mehrere Takte, bis es fertig ist. Anderer seite 
  shift Operation wurde schnell durch ALU physisich durchgeführt*/
  int pwmRot = analogWert >> 2;  //Shift die 10bits auf 8bits. Das entspricht die Wert zu 4 dividieren.
  int pwmGelb = 255 - pwmRot;
  // Gib die entsprechende PWM signal
  analogWrite(LEDRed, pwmRot);
  analogWrite(LEDYellow, pwmGelb);
  //Blink rote LED
  if (pwmRot < 10) {  // wenn die PWM LED unter eine Scwellwert, wurde normale LED ausgeschaltet
    digitalWrite(LEDRot, LOW);
  } else {
    // Frequenz von 1Hz (langsam) bis 10Hz (schnell)
    int freqRot = map(pwmRot, 10, 255, 1, 10);
    // Periode berechnen:
    // T = 1/f, da wir halbe periode brauchen und zwar in milisekunden, es ist 500/f
    int intervalRot = 500 / freqRot;
    if (millis() - startTimeRot >= intervalRot){
      startTimeRot = millis();
      zustandRot = !zustandRot;
      digitalWrite(LEDRot, zustandRot);
    }
  }
  //Blink gelbe LED, gleich wie rot
  if (pwmGelb < 10) {  
    digitalWrite(LEDGelb, LOW);
  } else {
    int freqGelb = map(pwmGelb, 10, 255, 1, 10);
    int intervalGelb = 500 / freqGelb;
    if (millis() - startTimeGelb >= intervalGelb){
      startTimeGelb = millis();
      zustandGelb = !zustandGelb;
      digitalWrite(LEDGelb, zustandGelb);
    }
  }
}
