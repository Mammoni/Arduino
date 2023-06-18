#include <LiquidCrystal_I2C.h> 
#define WS_PIN 7
#define SIGNAL_WS_PIN A3

int water_lvl = 0;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(9600);
  pinMode(WS_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(WS_PIN, LOW); // turn the sensor OFF
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Water level system");
  delay(2000);
  lcd.clear();
}

void value(){
    if (water_lvl < 30) {
    lcd.print("Empty ");
  } else if (water_lvl >= 30 && water_lvl < 310) {
    lcd.print("Low   ");
  } else if (water_lvl >= 310 && water_lvl < 450) {
    lcd.print("Medium");
  } else if (water_lvl >= 450){
    lcd.print("HIGH  ");
  }
}

void displ(){
  lcd.setCursor(0,0);
  lcd.print("Value: ");
  lcd.print(water_lvl);
  lcd.setCursor(0,1);
  lcd.print("W Level: ");
  value();
  delay(1000);
  lcd.clear();
}

void loop() {
  digitalWrite(WS_PIN, HIGH);
  delay(10);
  water_lvl = analogRead(SIGNAL_WS_PIN);
  digitalWrite(WS_PIN, LOW); 

  displ();
}
