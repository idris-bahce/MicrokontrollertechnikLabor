/*================ E23 == WiSe24/25 ==== LPr-Versuch 02 ==== Aufgabe 5
Aufgabe 5: MulƟfunkƟonslampe mit Tastern
 3 LEDs mit Vorwiderständen
 2 Taster (BuƩons)
 2 Widerstände a´ 10 k
Mehrmaliger sequenƟeller Tastendruck eines Tasters so µC-gesteuert zu mehreren Leutmodi der drei
LEDs führen. Der Druck auf einen zweiten Taster soll einen Reset bewirken und alle LEDs
Bevor Sie die Aufgabe 5 lösen,
sollten Sie sich mit dem Sinn und der Wirkungsweise von pull-up bzw. pull-down
Widerständen und der Tasterentprellung (Debouncing) beschäŌigt haben
[vergl. u.a. mit den entsprechenden Vorlesungsinhalten].
a) Bauen Sie eine Schaltung mit drei LEDs und zwei Tastern auf und sorgen Sie dafür, dass Ihre
beiden Taster eindeuƟge Zustände aufweisen (pull-up bzw. pull down)!
b) Programmieren Sie eine MulƟfunkƟonslampe die wie folgt auf TasterbetäƟgung reagiert,
wobei Sie bei beiden Tastern mit einer Ihnen bekannten SW-Methoden für hinreichende
Entprellung sorgen sollen!
 Startzustand: Alle drei LEDs sind aus.
 Nur Taster 1 wird gedrückt:
1. Tastendruck  LED1 an, LED2 u. LED3 aus
2. Tastendruck  LED2 an, LED1 u. LED3 aus
3. Tastendruck  LED3 an, LED1 u. LED2 aus
4. Tastendruck  LED1, LED2 u. LED3 an
5. Tastendruck  LED1 blinkt, LED2 u. LED3 an
6. Tastendruck  Lauflicht: erst LED1, dann LED2, dann LED3 usw. (jeweils ca. 1 s)
7. Wie 1. Tastendruck von Taster 1
 Nur Taster 2 wird gedrückt (zu beliebigem Zeitpunkt):
RESET auf Start  alle drei LEDs sind aus. 
**************************************************************************
**************************************************************************/
const int set = 2;
const int reseted = 4;

const int led1 = 5;
const int led2 = 7;
const int led3 = 9;

int count = 0; //Zustände von 1 bis 7
int gedrucktSpatSet = LOW; //Speichert die letzte zustand des tasters
int gedrucktSpatReset = LOW; //Speichert die letzte zustand des tasters

unsigned long timeAktuel; // statt delay benutzen wir aritmatik
unsigned long timeLast = 0; // statt delay benutzen wir aritmatik
int blink = LOW;

int folgeLED = 0; //case 6 folge count
unsigned long timeAktuelCase6; // statt delay benutzen wir aritmatik
unsigned long timeLastCase6 = 0; // statt delay benutzen wir aritmatik

//Prellen Massnahmen
unsigned long delay_time = 200; //200ms
unsigned long lastdebounce_time = 0;


void anfangZustand(){
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
}

//1. Tastendruck -> LED1 an, LED2 u. LED3 aus
void case_1(){
  digitalWrite(led1, 1);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
}

//2. Tastendruck -> LED2 an, LED1 u. LED3 aus
void case_2(){
  digitalWrite(led1, 0);
  digitalWrite(led2, 1);
  digitalWrite(led3, 0);
}

//3. Tastendruck -> LED3 an, LED1 u. LED2 aus 
void case_3(){
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 1);
}

//4. Tastendruck -> LED1, LED2 u. LED3 an
void case_4(){
  digitalWrite(led1, 1);
  digitalWrite(led2, 1);
  digitalWrite(led3, 1);
}

//5. Tastendruck -> LED1 blinkt, LED2 u. LED3 an
void case_5(){
  timeAktuel = millis();
  if(timeAktuel - timeLast >= 1000){ //blink in jeder sekunde ohne delay
    blink = !blink;
    timeLast = timeAktuel;
  }
  digitalWrite(led1, blink);
  digitalWrite(led2, 1);
  digitalWrite(led3, 1);
}

//6. Tastendruck -> Lauflicht: erst LED1, dann LED2, dann LED3 usw. (jeweils ca. 1 s)
void case_6(){
  timeAktuelCase6 = millis();
  if(timeAktuelCase6 - timeLastCase6 >= 1000){ 
    timeLastCase6 = timeAktuelCase6;
    folgeLED++;
    if(folgeLED > 2){
      folgeLED = 0;
    }
  }
  switch(folgeLED){
    case 0:
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      break;
    case 1:
      digitalWrite(led1, 0);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      break;
    case 2:
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 1);
      break;
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(set, INPUT);
  pinMode(reseted, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  // taster set und sein Prellen Massnahme. Es ist so ausgelegt, dass wenn man drücken bleibt, wird es nur einmal signal geben.
  unsigned long bounce_time = millis();
  int gedrucktAktuelSet = digitalRead(set);
  if(gedrucktAktuelSet == HIGH && gedrucktSpatSet == LOW && bounce_time - lastdebounce_time >= delay_time){
    count++;
    if(count == 7){
      count = 1;
    }
    lastdebounce_time = bounce_time;
  }

  // taster Reset und sein Prellen Massnahme. Es ist so ausgelegt, dass wenn man drücken bleibt, wird es nur einmal signal geben.
  int gedrucktAktuelReset = digitalRead(reseted);
  if(gedrucktAktuelReset == HIGH && gedrucktSpatReset == LOW && bounce_time - lastdebounce_time >= delay_time){
    count = 0;
    lastdebounce_time = bounce_time;
  }

  switch(count){
    case 0:
     anfangZustand();
     break;
    case 1:
     case_1();
     break;
    case 2:
     case_2();
     break;
    case 3:
     case_3();
     break;
    case 4:
     case_4();
     break;
    case 5:
     case_5();
     break;
    case 6:
     case_6();
     break;
  }

  gedrucktSpatSet = gedrucktAktuelSet;
  gedrucktSpatReset = gedrucktAktuelReset;
}
