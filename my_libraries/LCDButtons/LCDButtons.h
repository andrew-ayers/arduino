/*
    LCDButtons.h - Library for ANET 20x4 LCD button handling
    Copyright (c) 2020 by Andrew L. Ayers
    Licensed under the GNU Public License (GPL) Version 3
    http://www.gnu.org/licenses/gpl-3.0.en.html
*/

#ifndef LCDButtons_h
#define LCDButtons_h

#include "Arduino.h"

#define LCD_BUTTONS_NONE  0
#define LCD_BUTTONS_UP    1
#define LCD_BUTTONS_DOWN  2
#define LCD_BUTTONS_BACK  4
#define LCD_BUTTONS_ENTER 8
#define LCD_BUTTONS_MENU  16

class LCDButtons {
    private:
        byte _pin;
        byte _button;

        long _lastMillis = 0; // Last time the buttons were sampled

        int _buttonSamples = 0; // How many times we have seen new value?
        int _debounceSamples = 40; // Number of samples to take for debouncing
        int _debouncedVal = 0;  // The debounced button value

    public:
        LCDButtons(byte pin);
        void read();
        byte getButton();
};

#endif