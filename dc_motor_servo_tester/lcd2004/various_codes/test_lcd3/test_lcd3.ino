#include <LCDButtons.h>
#include <LiquidCrystal.h>

#define RSPin 6
#define EnablePin 7
#define DS4 9
#define DS5 10
#define DS6 11
#define DS7 12

#define LCDColumns 20
#define LCDRows 4

LCDButtons buttons(A2);

LiquidCrystal lcd(RSPin, EnablePin, DS4, DS5, DS6, DS7);

void setup() {
  Serial.begin(9600);

  initializeLCD();
  
  showLCDMessage();
}

void loop() {
  doButtonAction();
}

void initializeLCD() {
  lcd.begin(LCDColumns, LCDRows);
}

void showLCDMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("20x4 LCD Menu - v1.1");
}

void doButtonAction() {
  buttons.read();

  int button = buttons.getButton();

  if (button == LCD_BUTTONS_NONE) return;

  showLCDMessage();

  lcd.setCursor(0, 2);
  lcd.print("Selection: ");

  if (button == LCD_BUTTONS_UP) {
    // up
    lcd.print("UP");  
  }

  if (button == LCD_BUTTONS_DOWN) {
    // down
    lcd.print("DOWN");  
  }

  if (button == LCD_BUTTONS_BACK) {
    // left (back)
    lcd.print("BACK");  
  }

  if (button == LCD_BUTTONS_ENTER) {
    // right (enter)
    lcd.print("ENTER");  
  }

  if (button == LCD_BUTTONS_MENU) {
    // middle (menu)
    lcd.print("MENU");  
  }
}
