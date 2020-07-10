#include <LiquidCrystal.h>

#define RSPin 6
#define EnablePin 7
#define DS4 9
#define DS5 10
#define DS6 11
#define DS7 12

#define LCDColumns 20
#define LCDRows 4

#define Buttons A3

const int numReadings = 10;

int buttonVal = 0;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

LiquidCrystal lcd(RSPin, EnablePin,DS4,DS5,DS6,DS7);

// check - https://forum.arduino.cc/index.php?topic=8558.0

void setup()
{
  Serial.begin(9600);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  
  lcd.begin(LCDColumns, LCDRows); //Configure the LCD
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");
}

void loop()
{
  // subtract the last reading:
  total = total - readings[readIndex];
  
  // read from the sensor:
  readings[readIndex] = analogRead(Buttons);
  
  // add the reading to the total:
  total = total + readings[readIndex];
  
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;

  if (average != buttonVal) {
    buttonVal = average;
    // send it to the computer as ASCII digits
    Serial.println(buttonVal);
  }
  
  delay(1);        // delay in between reads for stability
}
