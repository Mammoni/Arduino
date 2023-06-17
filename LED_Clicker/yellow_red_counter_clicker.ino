#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <ezBuzzer.h>

ezBuzzer buzzer(3); 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0,4,5,6,7,3, POSITIVE);
int a = 1;
int con = 0;

void setup() {
    pinMode(9,OUTPUT);
    pinMode(8,OUTPUT);
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("Hello ");
    pinMode(7,INPUT_PULLUP);
    
}

void kliker(){
      lcd.clear();
      lcd.begin(16,2);
      lcd.setCursor(0, 0);
      lcd.print(a);
      delay(1000);
      lcd.clear();
        if(a%2 == 0){
          lcd.setCursor(0, 0);
          lcd.print("RED = ");
          lcd.setCursor(0, 1);
          lcd.print(a);
        }else{
          lcd.setCursor(0, 0);
          lcd.print("YELLOW = ");
          lcd.setCursor(0, 1);
          lcd.print(a);
        }
          a++;
  }

void loop() {
    buzzer.loop();
  if(digitalRead(7) == LOW){
    buzzer.beep(10);
    if(con == 0){
        digitalWrite(8,LOW);
        digitalWrite(9,HIGH);    
        con = 1;
        kliker();
    }else if(con == 1){
        digitalWrite(9,LOW);
        digitalWrite(8,HIGH);
        con = 0;
        kliker();
    }else{
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      delay(100);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
      con = 0;
      }
    
   }
}
