/*================ E23 == Sose25/26 ==== LPr-Versuch 04 ==== Aufgabe 1
a) Programmieren Sie den Mikrocontroller mit analogWrite() derart, dass eine an Pin D11
angeschlossene rote LED über einen Zeitraum von ca. 10 Sekunden langsam hell und dann
wieder dunkel wird und eine an Pin D10 angeschlossene gelbe LED dazu im Gegentakt dunkel
und hell wird (LED-Vorwiderstände a ´ca. 220-470 Ω NICHT vergessen!)
Hinweise:
 Mit analogWrite() angesteuerte Pins müssen nicht separat als OUTPUT gesetzt werden.
 Wenn Sie den Effekt der Helligkeitsveränderung deutlicher beobachten möchten, nutzen Sie zwei gleichfarbige –
vorzugsweise grüne LEDs – und erhöhen Sie ggf. die LED-Vorwiderstandswerte. 
**************************************************************************
**************************************************************************/
const int LEDRot = 11; //Rote LED
const int LEDGelb = 10; //Gelbe LED
int pwmValue = 0;
bool brighterRed = true;
int brighnessInSeconds = 5000; //Schreib die 10s in milisekunden als variable, es wird in 5 Sekunden hoch, 5 sekunden runter fahren
unsigned long startTime = millis(); //Anfang Zeit des Programmes


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDRot, OUTPUT);
  pinMode(LEDGelb, OUTPUT);
}

void loop() {
  // 10 sekunde Takt wurde von folgenden Gleichung gewährleistet:
  //In jeder 5 Sekunde außer if else wird abwechseln
  unsigned long elapsedTime = millis() - startTime;
  if(brighterRed){
    if(elapsedTime <= brighnessInSeconds){
      /*Wenn wir ein Elapsed Zeit zwischen 0 und 10 tausend haben und das zum 10 tausend dividieren, bekomen wir ein fliess komma Zahl zwischen 0 und 1
      When wir diese Zahl mit 255 multiplizieren, egal wie viel, bekommen wir ein Zahl zwischen 0 und 255. Es ist wichtig, weil es unser Analogwrite bits sind.*/
      pwmValue = int((elapsedTime*1.0/brighnessInSeconds) * 255); 
      /* Ich habe KI leistungsfähigere Code gefragt, gibt er das statt mein code Zeil oben:
      Ganzzahlige Mathematik: Die verstrichene Zeit wird direkt mit 255 multipliziert 
         (UL steht fuer Unsigned Long, um Überläufe zu vermeiden) und dann dividiert. 
         Das liefert einen korrekten PWM-Wert (0-255) ohne langsame Fließkommazahlen. 
      pwmValue = (elapsedTime * 255UL) / halfPeriodInMs;*/
      analogWrite(LEDRot, pwmValue);
      analogWrite(LEDGelb, (255 - pwmValue));
    }else{
      brighterRed = false;
      startTime = millis();
    }
    
  }else{
    unsigned long elapsedTime = millis() - startTime;
    if(elapsedTime <= brighnessInSeconds){
      /*Gleiche Vorgang nur umgekehrt*/
      pwmValue = int((elapsedTime*1.0/brighnessInSeconds) * 255); 
      analogWrite(LEDGelb, pwmValue);
      analogWrite(LEDRot, (255 - pwmValue));
    }else{
      brighterRed = true;
      startTime = millis();
    }
  }

}
