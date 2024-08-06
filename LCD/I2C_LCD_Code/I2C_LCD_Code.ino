#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )

void setup()
{
	// initialize the lcd
	lcd.init();
	// Turn on the Backlight
	lcd.backlight();
}

void loop()
{
	// Clear the display buffer
	lcd.clear(); 
	// Set cursor (Column, Row)
	lcd.setCursor(0, 0);
	// print "Hello" at (0, 0)	 
	lcd.print("Hello"); 
	// Set cursor (Column, Row)
	lcd.setCursor(0,1);
	// print "Geek" at (0, 1)
	lcd.print("Geek");

	delay(100);
}
