void Menue(){

// Menü wird geloopt solange "Einstellungen" Variable wahr ist  
  while(Einstellungen==true){

//Displaycache wird bereinigt
    display.clearDisplay();


//Menü kann durch Drücken beider Knöpfe verlassen werden    
    if (digitalRead(5)==HIGH&&digitalRead(3)==HIGH){
      Einstellungen=false;
      Anzeige=false;
      Kalibrierung=false;
    }

//zweiter Knopf wird zur Navigation genutzt, indem er eine Variable verändert, die zur Auswahl von Menüoptionen genutzt wird 
    if (digitalRead(5)==HIGH&&KnopfDruck==false){
      KnopfDruck=true;
      KnopfPosition=KnopfPosition+1;
      if (KnopfPosition==4){
        KnopfPosition=1;  
      }
    }

//Grundlegende Menüoptionen, zwei Untermenüs und ein "exit" mit dem das Menü verlassen wird
    if(Einstellungen==true&&Anzeige==false&&Kalibrierung==false){
      display.setRotation(0);
      display.setCursor(0,0);
      display.print("Anzeige");
      display.setCursor(0,10);
      display.print("Kalibrierung");
      display.setCursor(0,20);
      display.print("exit");
//In Abhängigkeit der Positionsvariable wird ein "x" an den Menüoptionen angezeigt. Ein Druck des Menüknopfs wählr diese aus
      switch(KnopfPosition){
        case 1:
          display.setCursor(120,0);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            Anzeige=true;
            KnopfDruck=true; 
          }
          break;
        case 2:
          display.setCursor(120,10);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            Kalibrierung=true;
            KnopfDruck=true; 
          }
          break;
        case 3:
          display.setCursor(120,20);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            Einstellungen=false;
            KnopfDruck=true; 
          }
          break;
      }
    }

//"Anzeige" Untermenü  
    if(Einstellungen==true&&Anzeige==true&&Kalibrierung==false){
      display.setRotation(0);
      display.setCursor(0,0);
// Auswahl von "Display drehen" verändert eine Variable, welche die Position des Displays speichert
      if(RotationsWert==0){
        display.print("Display drehen -");
      }
      else{
        display.print("Display drehen |");
      }
// Es gibt die Möglichkeit die unkalibrierten Werte anzuzeigen. Interessant, für UV Messungen
      display.setCursor(0,10);
      if(Rohwerte==false){
        display.print("Rohwerte Anzeigen");
      }
      else{
        display.print("Bearbeitete Werte");
      }
      display.setCursor(0,20);
      display.print("zurueck");
      switch(KnopfPosition){
        case 1:
          display.setCursor(120,0);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            RotationsWert=RotationsWert+1;
            if(RotationsWert==2){
              RotationsWert=0; 
            }
            if(RotationsWert==1){
              xPixel=32;
              yPixel=128;
            }
            if(RotationsWert==0){
              xPixel=128;
              yPixel=32;
            }
          }
          break;
        case 2:
          display.setCursor(120,10);
          display.print("x"); 
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            Rohwerte = !Rohwerte; 
          }
          break;
        case 3:
          display.setCursor(120,20);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            Anzeige=false; 
          }
          break;
      }
    }

// "Kalibrierung"-Untermenü besitzt die Möglichkeiten "Raumkalibrierung" und "Strahlerkalibrierung", welche eigene Funktionen Auslösen (s. Kalibrierung1 und Kalibrierung2)
    if(Einstellungen==true&&Anzeige==false&&Kalibrierung==true){
      display.setRotation(0);
      display.setCursor(0,0);
      display.print("Raumkalibrierung");
      display.setCursor(0,10);
      display.print("Strahlerkalibrierung");
      display.setCursor(0,20);
      display.print("zurueck");
      switch(KnopfPosition){
        case 1:
          display.setCursor(120,0);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            Kalibrierung1();
          }
          break;
        case 2:
          display.setCursor(120,10);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            Kalibrierung2(); 
          }
          break;
        case 3:
          display.setCursor(120,20);
          display.print("x");
          if (digitalRead(3)==HIGH&&KnopfDruck==false){
            KnopfDruck=true;
            Kalibrierung=false; 
          }
          break;
      }
    }
    
// Auch hier wird die Knopfdruckvariable zurückgesetzt
     if (digitalRead(5)==LOW&&digitalRead(3)==LOW){
      KnopfDruck=false;
     }
  display.display();
  }
}
