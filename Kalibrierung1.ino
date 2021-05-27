void Kalibrierung1(){

  //5-Sekündiger Countdown
  for(int i=0;i<5;i++){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE); 
    display.setCursor(0, 0); 
    display.print("Raumkalibrierung in:");  
    display.print(5-i);
    delay(1000);
    display.display();  
  }
 //Messwerte werden aufgenommen und abgespeichert, diese werden später von allen Messwerten abgezogen
    for (int i=0;i<LED_Anzahl+2;i++){
    switch(i){
    case 0:
    case 1:
    case 2:
    case 3:
    Verschiebung[i]= analogRead(i)-5;
    Serial.print("Verschiebung an Diode ");
    Serial.print(i+1);
    Serial.print(" ");
    Serial.println (Verschiebung[i]);
    break;
//Wichtig zu bemerkten ist an dieser Stelle, dass die Analogpins 4 und 5 unbelegt sind, da es sich hier ebenfalls um SCL und SDA Pins handelt, die vom Display genutzt werden
    case 4:
    case 5:
    break;  
    default:
    Verschiebung[i-2]= analogRead(i)-5;
    Serial.print("Verschiebung an Diode ");
    Serial.print(i-1);
    Serial.print(" ");
    Serial.println (Verschiebung[i-2]);
    break;
    }
}
 
display.display();  
}
