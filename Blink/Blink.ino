const int buttonPin = 0;     // GPIO 0 entspricht dem FLASH-Button
const int ledPin = 2;        // Die interne LED (GPIO 2 / D4)
const int ledPin2 = 4;        // externe LED (GPIO 4 / D2)
int zeit = 1000;              //Warte Zeit
bool ledStatus = LOW;
unsigned long letzteBlinkZeit = 0; 

void setup() {
  // INPUT_PULLUP aktiviert den internen Widerstand, damit der Pin stabil HIGH bleibt
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long aktuelZeit = millis();
  if((aktuelZeit - letzteBlinkZeit) >= zeit){
    letzteBlinkZeit = aktuelZeit;
    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
    digitalWrite(ledPin2, ledStatus);
  }
  
  if (digitalRead(buttonPin) == LOW) {    
    delay(200);
    zeit -= 100;
    if(zeit <= 0){
      zeit = 1000;
    }  
    while(digitalRead(buttonPin) == LOW);
  } 
}