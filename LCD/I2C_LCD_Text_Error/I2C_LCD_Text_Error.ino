//**********************************************************************
//   My Channel: https://www.youtube.com/c/TeachMeSomething
//**********************************************************************
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);


void setup() 
{
  lcd.begin();
  lcd.clear();
}
void loop() 
{
  lcd.setCursor(4,0);
  lcd.print("Welcome");
  lcd.setCursor(0,1);
  lcd.print("I2C LCD Project");
}
