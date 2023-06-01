//c++ code

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

const int merah1 = 6; 
const int hijau2 = 5; 
const int biru3 = 4; 
const int piezo = 2; 
const int sensor = A0; 
float out_sensor;
float celcius_sensor;

void setup() { 
  pinMode(merah1, OUTPUT); 
  pinMode (hijau2, OUTPUT); 
  pinMode (biru3, OUTPUT); 
  pinMode (piezo, OUTPUT); 
  pinMode (sensor, INPUT); 
  Serial.begin(9600); 
  
  lcd.begin(16, 2);
  lcd.print("PENUGASAN OPREC");
  lcd.setCursor(0,1);
  lcd.print("      DSS");
  delay (2000);
  lcd.clear();
}

void loop() { 
 out_sensor = analogRead(sensor);
 celcius_sensor = ((out_sensor * (16000/1024))-500)/10;
  
  if(celcius_sensor >= -40 && celcius_sensor < 6){
  {{
    digitalWrite(merah1, HIGH); 
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
    tone(piezo, 400); 
  }
   delay(200);} 
  {{
    digitalWrite(merah1, LOW); 
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
    tone(piezo,300); 
  }
   delay(200);}
    
   lcd.setCursor(0,0);
   lcd.print ("Suhu Sangat     "); 
   lcd.setCursor(0,1);
   lcd.print ("Dingin          ");
   lcd.setCursor(7,1);
   lcd.print (celcius_sensor);
   lcd.setCursor(14,1);
   lcd.print ("C               ");
   
  }
  
  else if(celcius_sensor >= 6 && celcius_sensor < 16){
  {{
    digitalWrite(merah1, HIGH); 
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
    tone(piezo, 400); 
  }
   delay(900);} 
  {{
    digitalWrite(merah1, LOW); 
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
    noTone(piezo); 
  }
   delay(900);} 
    
   lcd.setCursor(0,0);
   lcd.print ("Suhu Dingin ");
   lcd.setCursor(0,1);
   lcd.print (" ");
   lcd.setCursor(1,1);
   lcd.print (celcius_sensor);
   lcd.setCursor(5,1);
   lcd.print (" ");
   lcd.setCursor(6,1);
   lcd.print ("Celcius         ");
   noTone(piezo); 
  }
  
  else if(celcius_sensor >= 16 && celcius_sensor < 39){
  {{
    digitalWrite(merah1, HIGH); 
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
  }
   delay(900);} 
  {{
    digitalWrite(merah1, LOW); 
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
  }
   delay(900);} 
    
   lcd.setCursor(0,0);
   lcd.print ("Suhu Normal     ");
   lcd.setCursor(0,1);
   lcd.print (" ");
   lcd.setCursor(1,1);
   lcd.print (celcius_sensor);
   lcd.setCursor(6,1);
   lcd.print (" ");
   lcd.setCursor(7,1);
   lcd.print ("Celcius         ");
  }
  
  else if(celcius_sensor >= 39 && celcius_sensor < 65){
  {{
    digitalWrite(merah1, HIGH); 
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
  }
   delay(400);} 
  {{
    digitalWrite(merah1, LOW); 
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
  }
   delay(400);}
    
    lcd.setCursor(0,0);
    lcd.print ("Suhu Panas      ");
    lcd.setCursor(0,1);
   	lcd.print (" ");
    lcd.setCursor(1,1);
    lcd.print (celcius_sensor);
    lcd.setCursor(5,1);
   	lcd.print (" ");
    lcd.setCursor(6,1);
   	lcd.print ("Celcius          ");
    tone(piezo, 400); 
  }
 
  else if(celcius_sensor > 65){
  {{
    digitalWrite(merah1, HIGH); 
    digitalWrite(hijau2, HIGH);
    digitalWrite(biru3, HIGH);
    tone(piezo, 400); 
  }
   delay(200);} 
  {{
    digitalWrite(merah1, LOW); 
    digitalWrite(hijau2, LOW);
    digitalWrite(biru3, LOW);
    tone(piezo, 300); 
  }
   delay(200);}
    
    lcd.setCursor(0,0);
    lcd.print ("Suhu Sangat     "); 
    lcd.setCursor(0,1);
    lcd.print ("Panas  ");
    lcd.setCursor(7,1);
    lcd.print (celcius_sensor);
    lcd.setCursor(12,1);
   	lcd.print (" ");
    lcd.setCursor(13,1);
   	lcd.print (" C  ");
  }
}