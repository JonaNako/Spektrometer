void WerteAufnehmen(){
// Anhand der eingetragenen Wellenlängen werden die Anzeigepositionen der LEDs auf dem Display errechnet
  for (int i=0;i<LED_Anzahl;i++){
    PositionenDisplay[i]=map(Positionen[i],Positionen[LED_Anzahl-1],Positionen[0],0,xPixel-1);
     /*Serial.print("Position von Diode ");
     Serial.print(i+1);
     Serial.print(" ");
     Serial.println (PositionenDisplay[i]); */
    } 
//Messwerte werden aufgenommen und in einer Liste gespeichert
    for (int i=0;i<LED_Anzahl+2;i++){
      switch(i){
        case 0:
        case 1:
        case 2:
        case 3:
          FarbSensoren[i]=analogRead(i);
          break;
        case 4:
        case 5:
          break;
        default:
          FarbSensoren[i-2]=analogRead(i);
          break;  
        }
  }
}
