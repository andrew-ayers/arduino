/*
    5x8_characters.c - Custom 5x8 character definitions for
    HD44780 and compatible LCD character displays
    
    Copyright (c) 2020 by Andrew L. Ayers
    Licensed under the GNU Public License (GPL) Version 3
    http://www.gnu.org/licenses/gpl-3.0.en.html

    To use:

        Copy and paste the definitions into your codebase
        as needed, then call:

        lcd.createChar(cgram_position, arrayname);
        lcd.write(cgram_position)

        Where: cgram_position = 0 - 7
*/

// Single-character symbol definitions

// Smiley Face
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

// Frowning Face
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

// Stickman
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

// Pacman (facing right)
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

// Ghost
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

// Thermometer (indicator for temperature)
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

// Water Droplet (indicator for humidity or similar)
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

// Heart
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

// Halftone block
byte halftone[] = {
    B10101,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010,
    B10101,
    B01010    
};

// Rounded degree symbol (temperature)
byte degree[] = {
    B01100,
    B10010,
    B10010,
    B01100,
    B00000,
    B00000,
    B00000,
    B00000
};

// Closed lock symbol
byte locked[] = {
    B00000,
    B01110,
    B10001,
    B10001,
    B11111,
    B11011,
    B11011,
    B11111
};

// Opened lock symbol
byte unlocked[] = {
    B00000,
    B01110,
    B10001,
    B10000,
    B11111,
    B11011,
    B11011,
    B11111    
};

// Key symbol
byte key[] = {
    B00111,
    B00100,
    B00110,
    B00100,
    B01110,
    B10001,
    B10001,
    B01110
};

// Up arrow symbol
byte uparrow[] = {
    B00100,
    B01110,
    B10101,
    B00100,
    B00100,
    B00100,
    B00000,
    B00000
};

// Down arrow symbol
byte downarrow[] = {
    B00000,
    B00000,
    B00100,
    B00100,
    B00100,
    B10101,
    B01110,
    B00100
};

// Rotational arrow symbol (Redo, Indicator for RPM, etc)
byte rotarrow[] = {
    B00000,
    B01110,
    B10001,
    B10001,
    B10101,
    B01100,
    B11100,
    B00000
};

// Multi-character symbol definitions
//
// To use these you must display them next to each
// other, left-to-right

// Progress Bar
byte leftpbar[] = {
    B01111,
    B11000,
    B10011,
    B10111,
    B10111,
    B10011,
    B11000,
    B01111
};

byte fullpbar[] = {
    B11111,
    B00000,
    B01110,
    B01110,
    B01110,
    B01110,
    B00000,
    B11111
};

byte rghtpbar[] = {
    B11110,
    B00011,
    B11001,
    B11101,
    B11101,
    B11001,
    B00011,
    B11110
};

// Gauge (could be expanded to indicate multiple "values")
byte leftgauge[] = {
    B00000,
    B00011,
    B00100,
    B01000,
    B01000,
    B10000,
    B10001,
    B11111
};

byte rghtgauge[] = {
    B00000,
    B11000,
    B00100,
    B00010,
    B01010,
    B10001,
    B00001,
    B11111
};