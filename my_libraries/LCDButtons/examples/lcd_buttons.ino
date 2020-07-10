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

byte upper = B0000;
byte lower = B0000;

void setup() {
  Serial.begin(9600);
  
  initLCD();
}

void loop() {
  doButtons();
}

void initLCD() {
  lcd.begin(LCDColumns, LCDRows);

  createCustomChars();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("20x4 LCD Characters");

  showCharacter();  
}

void createCustomChars() {
  byte smiley[] = {
    B00000,
    B00000,
    B10001,
    B00000,
    B00000,
    B10001,
    B01110,
    B00000
  };

  byte frowny[] = {
    B00000,
    B00000,
    B10001,
    B00000,
    B00000,
    B01110,
    B10001,
    B00000
  };

  byte manny[] = {
    B01110,
    B01110,
    B00100,
    B11111,
    B10101,
    B00100,
    B01010,
    B10001
  };

  byte pacman[] = {
    B00000,
    B01110,
    B11011,
    B11110,
    B11100,
    B11110,
    B11111,
    B01110
  };

  byte ghost[] = {
    B00000,
    B01110,
    B11111,
    B10101,
    B10101,
    B11111,
    B11111,
    B10101,
  };

  byte thermometer[] = {
    B00100,
    B01010,
    B01010,
    B01010,
    B01110,
    B11111,
    B11111,
    B01110
  };

  byte droplet[] = {
    B00100,
    B00100,
    B01010,
    B01010,
    B10001,
    B10001,
    B10001,
    B01110
  };

  byte heart[] = {
    B00000,
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000
  };

  lcd.createChar(0, smiley);
  lcd.createChar(1, frowny);
  lcd.createChar(2, manny);
  lcd.createChar(3, pacman);
  lcd.createChar(4, ghost);
  lcd.createChar(5, thermometer);
  lcd.createChar(6, droplet);
  lcd.createChar(7, heart);
}

void showCharacter() {
  byte character = upper << 4 | lower;

  lcd.setCursor(0, 1);
  lcd.print("                    ");

  lcd.setCursor(0, 1);
  
  lcd.print("B");

  for (byte i=0; i<=7; i++) {
    lcd.print((character >> (7 - i)) & B00000001);
  }
  
  lcd.print(" 0x");
  lcd.print(character, HEX);
  lcd.print(" ");
  lcd.print(character, DEC);

  lcd.setCursor(9, 3);
  lcd.write(character);
}

void doButtons() {

  buttons.read();

  int button = buttons.getButton();

  if (button == LCD_BUTTONS_NONE) return;

  if (button == LCD_BUTTONS_UP) {
    lower -= 1;
  }

  if (button == LCD_BUTTONS_DOWN) {
    lower += 1;
  }

  if (button == LCD_BUTTONS_BACK) {
    upper -= 1;
  }

  if (button == LCD_BUTTONS_ENTER) {
    upper += 1;
  }

  if (button == LCD_BUTTONS_MENU) {
    upper = 0;
    lower = 0;
  }

  lower = lower & B00001111;
  upper = upper & B00001111;
  
  showCharacter();
}
