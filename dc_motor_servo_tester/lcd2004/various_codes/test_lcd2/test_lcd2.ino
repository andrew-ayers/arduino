#include <LiquidCrystal.h>

#define RSPin 6
#define EnablePin 7
#define DS4 9
#define DS5 10
#define DS6 11
#define DS7 12

#define LCDColumns 20
#define LCDRows 4

long lastMillis = 0; // Last time the buttons were sampled

int buttonVal = 0; // The value of the analog input pin for the buttons
int buttonTotal = 0;
int buttonSamples = 0; // How many times we have seen new value?
int debounceSamples = 40; // Number of samples to take for debouncing
int debouncedVal = 0;  // The debounced button value

LiquidCrystal lcd(RSPin, EnablePin,DS4,DS5,DS6,DS7);

void setup() {
  Serial.begin(9600);

  initializeLCD();
  
  showLCDMessage();
}

void loop() {
  readButtons();
}

void initializeLCD() {
  lcd.begin(LCDColumns, LCDRows);
}

void showLCDMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("20x4 LCD Menu - v1.0");
}

int readButtons() {  
  if (millis() != lastMillis) {
    
    buttonVal = analogRead(A2);

    if (buttonVal == debouncedVal && buttonSamples > 0) {
      buttonSamples--;    
    }
    
    if (buttonVal != debouncedVal) {
      buttonSamples++;
    }
    
    // If buttonVal stays the same value for the 
    // debounce period, switch to it
    if (buttonSamples > debounceSamples) {
      debouncedVal = buttonVal;
     
      // If a button has been pressed, do something with it
      if (debouncedVal < 1000) {
        doButtonAction();
      }

      buttonSamples = 0;
    }
   
    lastMillis = millis();
  }  
}

void doButtonAction() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("20x4 LCD Menu - v1.0");

  lcd.setCursor(0, 2);
  lcd.print("Selection: ");
  
  if (debouncedVal > 680 && debouncedVal < 710) {
    // up
    lcd.print("UP");  
  }

  if (debouncedVal > 160 && debouncedVal < 190) {
    // down
    lcd.print("DOWN");  
  }

  if (debouncedVal > 70 && debouncedVal < 100) {
    // left (back)
    lcd.print("BACK");  
  }

  if (debouncedVal > 490 && debouncedVal < 520) {
    // right (enter)
    lcd.print("ENTER");  
  }

  if (debouncedVal > 300 && debouncedVal < 330) {
    // middle (menu)
    lcd.print("MENU");  
  }
}
