#include <LiquidCrystal_I2C.h> 
const int PIN_RED   = 5;
const int PIN_GREEN = 6;
const int PIN_BLUE  = 9;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  pinMode(7,INPUT_PULLUP);

  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Color");
  delay(2000);
  lcd.clear();
  
}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}
int c = 0;
void loop() {
  if(digitalRead(7)== LOW){
    if(c == 0){
      setColor(0,0,255);
      lcd.setCursor(0,0);
      lcd.print("RED");
      delay(1000);
      lcd.print(" + ");
      c++;
    }else if(c == 1){
      setColor(255,0,0);
      lcd.print("BLUE");
      delay(1000);
      lcd.print(" = ");
      c++;
    }else if(c == 2){
      setColor(255,0,255);
      lcd.clear();
      lcd.print("PURPLE");
      delay(1000);
      c++;
    }else if(c == 3){
      analogWrite(PIN_RED,   LOW);
      analogWrite(PIN_GREEN, LOW);
      analogWrite(PIN_BLUE,  LOW);
      lcd.clear();
      delay(1000);
      c++;  
    }else{
     c = 0;  
    }
    
  }
    
}
