/*================ E23 == Sose25/26 ==== LPr-Versuch 03 ==== Aufgabe 1
Aufgabe 1: PotenƟometer als Messwertgeber und LED als Schwellwertanzeiger
a) Realisieren Sie die Schaltung mit PotenƟometer und einer Einzel-LED an D12 zur
Schwellwertanzeige (Vorwiderstand nicht vergessen)!
b) Verwenden Sie den PotenƟometereinstellwert wie einen analogen Sensor/Messfühler und
lesen Sie Spannungswerte analog ein:
 Analogeingang A0 verwenden;
 analogRead()-Anweisung verwenden; Mit welcher Auflösung arbeitet der ADC des
ATmega328?
Schreiben Sie einen Programmcode und kommenƟeren Sie den code vollumfänglich!
Zu realisierende FunkƟonen im µC-code zu sind:
c) Die erfassten ADC-Werte in Spannungswerte umrechnen
d) Die ADC-Werte und zugehörigen Spannungswerte spaltenweise auf dem seriellem Monitor
ausgeben.
e) Die ADC-Werte als Zeitreihe auf dem seriellem PloƩer zeigen können.
f) Eine LED mit Vorwiderstand an D12 bei MiƩenstellung des PotenƟometers
schwellwertabhängig an- bzw ausschalten.
g) Laden Sie Ihren Code auf den µC und testen Sie Ihre Lösung!
h) Speichern Sie Ihre finale Version zur späteren Verwendung ab! 
**************************************************************************
**************************************************************************/


const int LED = 12; // LED pin als D12
const int potPin = A0;  // Potentiometer pin als A0
int analogWert = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(potPin, INPUT); 
  Serial.begin(9600); // Öffne die serielle Schnittstelle bei 9600 Bit/s

}

  //c) Die erfassten ADC-Werte in Spannungswerte umrechnen 
  // 5V / 1023 = 0.00488758553 -> das ist die Auflösung

float spannungsWert(int wert){
  return (5/1023.0) * wert;
}


void loop() {
  // put your main code here, to run repeatedly:
  //analogRead()-Anweisung verwenden; Mit welcher Auflösung arbeitet der ADC des ATmega328? 
  //Es ist 10 bit. Das heißt 1024 bzw mit 0 1023 Auflösung
  analogWert = analogRead(potPin);

  float volt = spannungsWert(analogWert);
  Serial.println(analogWert);


  // Wenn die potentiometer über der halben Wert, wird es leuchten
  if((analogWert >= 400) && (analogWert <= 600)){
    digitalWrite(LED, 1);
  }else{
    digitalWrite(LED, 0);
  }


}
