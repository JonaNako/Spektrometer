// Einbindung der Bibliotheken für das OLED Display
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

//Variablen für den ResetPIN des OLED wird definiert.
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//Hier müssen die Werte für die LEDs eingetragen werden
#define LED_Anzahl 9                       //Hier wird eingetragen wie viele LEDs verwendet werden
int Positionen[LED_Anzahl]={650,625,591,565,525,500,465,428,400};  //immer von groß nach klein
float FaktorenKontrolle[LED_Anzahl]={910,1040,1100,1150,940,720,260,110,50};

//Definition von Variablen für die Normierung aufs Display
int PositionenDisplay[LED_Anzahl];
int xPixel=32;
int yPixel=128;
int Obergrenze=10;

//Definition von Variablen für die Aufnahme und Normierung der Messwerte
int FarbSensoren[LED_Anzahl];
long Pixel[32];

//Definition von Variablen für die Kalibrierung der Messwerte
int Verschiebung[LED_Anzahl]={0,0,0,0,0,0};
float Faktoren[LED_Anzahl]={100,100,100,100,100,100,100,100,100};
float FaktorenAufnahme[LED_Anzahl];

//Definition von Variablen für das Menü
bool Einstellungen=false;
bool Anzeige=false;
bool Kalibrierung=false;
bool KnopfDruck=false;
bool Rohwerte=false;
int RotationsWert=1;
int KnopfPosition=1;

void setup()
{
//Seriellen Monitor Initialisieren für die Auswertung mit dem Laptop
  Serial.begin(9600);

// Hier werden die Pull-up Widerstände des Arduinos ausgeschaltet
  _SFR_IO8(0x35) |= 0x10;

//Die Referenzspannung der analogen Eingänge wird von 5V auf 3,3V gelegt (Wichtig! Eine Verbindung zwischen 3,3V und AREF muss bestehen s. Steckplan)
  analogReference(EXTERNAL); 

// einige notwendige Zeilen für die Nutzung des Displays
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE); 

//Definition der KnopfPINs als Input
  pinMode(3,INPUT);
  pinMode(5,INPUT);
}




void loop() {

// Gibt an wie das Display ausgerichtet sein soll ( kann im Menü geändert werden)
  display.setRotation(RotationsWert);  

// Bei Druck des Menüknopf wird das Menü geöffnet
  if(digitalRead(3)==HIGH&&KnopfDruck==false){
    KnopfDruck=true;
    Einstellungen=true;
    Menue();
  }
  
// Messwerte werden aufgenommen (s. WerteAufnehmen)
  WerteAufnehmen();

// Messwerte werden auf dem Display angezeigt (s. DisplayAnzeigen)
  DisplayAnzeigen();
  
//Eine Variable die verhindert, dass ein Knopf durchgedrückt wird, wird zurückgesetzt  
  if (digitalRead(5)==LOW&&digitalRead(3)==LOW){
    KnopfDruck=false;
  }
  
//kurzes Delay, damit Übertaktung verhindert wird
  delay(20);
}
