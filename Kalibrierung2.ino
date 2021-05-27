void Kalibrierung2(){
//5-Sekündiger Cooldown
  for(int i=0;i<5;i++){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE); 
    display.setCursor(0, 0); 
    display.print("Strahlerkalibrierung in:");  
    display.print(5-i);
    delay(1000);
    display.display();  
  }
//Messwerte werden aufgenommen
  for (int i=0;i<LED_Anzahl+2;i++){
    switch(i){
    case 0:
    case 1:
    case 2:
    case 3:
    FaktorenAufnahme[i]=analogRead(i);
    break;
    case 4:
    case 5:
    break;  
    default:
    FaktorenAufnahme[i-2]=analogRead(i);
    Serial.println(i);
    break;
    }
    
  }
  for(int i=0;i<LED_Anzahl;i++){
//Es werden Faktoren Festgehalten mit denen die Messwerte multipliziert werden müssen, um Kontrollfaktoren zu erhalten. Wichtig ist, dass in dieser Formel die Ergebnisse aus der Raumkalibrierung vorkommen, diese also zuvor ausgeführt worden sein muss
    Faktoren[i]=FaktorenKontrolle[i]/(FaktorenAufnahme[i]-Verschiebung[i]);
   Serial.print("Faktor für Diode ");
   Serial.print(i+1);
   Serial.print(" ");
   Serial.println (Faktoren[i]);
  }
}
