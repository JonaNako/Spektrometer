void DisplayAnzeigen(){
display.clearDisplay();
//kurze Überprüfung, ob Rohwerte oder Kalibrierte Werte angezeigt werden sollen
  if(Rohwerte==false){
    Serial.print("Kalbirierte Werte ");
//Im Fall der Kalibrierten Werte werden sie hier errechnet
    for(int k=0;k<LED_Anzahl;k++){
      Pixel[k]=(FarbSensoren[k]-Verschiebung[k])*Faktoren[k]/10;
//Die Obergrenze für die Normierung aufs Display wird gefunden
      while(Pixel[k]>Obergrenze){
        Obergrenze=Obergrenze+10; 
      }
      Serial.print(Pixel[k]);
      Serial.print(" "); 
 // Werte werden aufs Display normiert
      Pixel[k]=map(Pixel[k],0,Obergrenze,yPixel-1,8);
      if (Pixel[k]>yPixel-1){
        Pixel[k]=yPixel-1;
      }
   
    }
    Serial.println();
  }
  else{
// Hier ist der Fall, falls die Rohwerte-Option ausgewählt wurde
    Serial.print("Rohwerte ");
    for(int k=0;k<LED_Anzahl;k++){
      Serial.print(FarbSensoren[k]);
      Serial.print(" ");
      while(FarbSensoren[k]>Obergrenze){
        Obergrenze=Obergrenze+10; 
      }
      Pixel[k]=map(FarbSensoren[k],0,Obergrenze,yPixel-1,8);
      if (Pixel[k]>yPixel-1){
        Pixel[k]=yPixel-1;       
      }
                 
    }
    Serial.println();        
  }
//An den Stellen, wo sich LEDs befinden werden Linien von unten bis oben gezogen  
for(int k=0;k<LED_Anzahl;k++){  
  display.drawLine(PositionenDisplay[k],127,PositionenDisplay[k],Pixel[k], WHITE);
}
//und auch Linien zwischen den Messwerten
for(int k=0;k<LED_Anzahl-1;k++){
  display.drawLine(PositionenDisplay[k],Pixel[k],PositionenDisplay[k+1],Pixel[k+1], WHITE);
}
//Die Obergrenze wird auch auf dem Display ausgegeben, da über sie Rückschlüsse über die Intensität des Lichtes gemacht werden kann
display.setCursor(0,0);
display.print("I=");
display.print(Obergrenze);
display.display();
Obergrenze=10;
}
