/* 
Mini OLED display an SAMD21 
Wagenanzeige für die RhB
*/
#include <Arduino.h>
#include <U8g2lib.h>

// Definiere die Breite und Höhe des Displays
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define PIN_TASTER 6  

// Erstelle ein Display-Objekt
U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED

int Station = 1;

void setup() {
  // Initialisiere die serielle Kommunikation, PIN Reedkontakt
  Serial.begin(9600);
  u8g2.begin();
  pinMode(PIN_TASTER, INPUT_PULLUP);
  u8g2.clearBuffer(); // Bildschirm löschen
}

void loop() {
  int zustandTaster = digitalRead(PIN_TASTER); // Tasterzustand einlesen
  int zustandTaster_old = LOW;

  // Prüfen des Tasterzustandes:
  if (zustandTaster == LOW) {    //wenn gedrückt (LOW) ...
   Station = Station+1; 
   u8g2.clearBuffer(); // Lösche Display 
   u8g2.sendBuffer(); // Aktualisiere das Display
   // Digitaleingang entprellen    
        if (zustandTaster != zustandTaster_old)
            {
              // normale Bearbeitung: losgelassen / gedrückt etc...
              zustandTaster_old = zustandTaster;
              delay(10);              // 10 millisekunden warten, eine Änderung danach wird wieder eine echte sein.
            }
   }//END IF
    
      //  Display Vorlauf ausgeben
        u8g2.setFont(u8g2_font_helvR08_tr);	// choose a suitable font);	// choose a suitable font
        u8g2.drawStr(0,10,"Bernina Express");	// write something to the internal memory
        u8g2.setFont(u8g2_font_pressstart2p_8u);	// choose a suitable font
        u8g2.setFontMode(0); //setInverseFont(1);
        u8g2.setDrawColor(0);
        u8g2.drawStr(0,22,"PE 951");	// write something to the internal memory
        u8g2.setFontMode(1);
        u8g2.setDrawColor(1);
        u8g2.setCursor(0, 0); // Cursor zurücksetzen
        u8g2.setFont(u8g2_font_helvR08_tr);	// choose a suitable font
        u8g2.setCursor(62, 22);
        u8g2.println(Station); // Eingabe anzeigen
        u8g2.sendBuffer(); // Aktualisiere das Display
        switch (Station) 
        {
        case 1: 
          u8g2.drawStr(0,32,"Chur               08:17");	// 1
          break;
        case 2:
          u8g2.drawStr(0,32,"Thusis             08:52");	// 2
          break;
        case 3:   
          u8g2.drawStr(0,32,"Tiefencastel       09:14");	// 3
          break;
        case 4:
          u8g2.drawStr(0,32,"Filisur            09:32");	// 4
          break;
        case 5:  
          u8g2.drawStr(0,32,"Bergün             09:46");	// 5
          break;
        case 6:
          u8g2.drawStr(0,32,"Pontresina         10:25");	// 6
          break;
        case 7:
          u8g2.drawStr(0,32,"Bernina Diavolezza 10:42");	// 7
          break;
        case 8:  
          u8g2.drawStr(0,32,"Ospizio Bernina    16:19");	// 8
          break;
        case 9:  
          u8g2.drawStr(0,32,"Poschiavo          12:01");	// 9
          break;
        case 10:  
          u8g2.drawStr(0,32,"Le Prese           12:20");	// 10
          break;
        case 11:  
          u8g2.drawStr(0,32,"Tirano             12:49");	// 11
          break;
        case 12:  
          Station=1;
          u8g2.clearBuffer(); // Lösche Display 
          break;
        default:
                break;
         
         }//END switch
}//END loop