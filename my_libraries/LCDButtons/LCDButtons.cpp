/*
    LCDButtons.cpp - Library for ANET 20x4 LCD button handling
    Copyright (c) 2020 by Andrew L. Ayers
    Licensed under the GNU Public License (GPL) Version 3
    http://www.gnu.org/licenses/gpl-3.0.en.html
*/

#include "Arduino.h"
#include "LCDButtons.h"

LCDButtons::LCDButtons(byte pin) {
    _pin = pin;
}

void LCDButtons::read() {

    _button = LCD_BUTTONS_NONE;

    if (millis() != _lastMillis) {
    
        int buttonVal = analogRead(_pin);

        if (buttonVal == _debouncedVal && _buttonSamples > 0) {
            _buttonSamples--;    
        }
        
        if (buttonVal != _debouncedVal) {
            _buttonSamples++;
        }
        
        // If buttonVal stays the same value for the debounce period, switch to it
        if (_buttonSamples > _debounceSamples) {
            _debouncedVal = buttonVal;
            
            // If a button has been pressed, set the action
            if (_debouncedVal < 1000) {

                // Note: Range values were determined via physical 
                // objective testing and may need adjustment
                if (_debouncedVal > 680 && _debouncedVal < 710) {
                    _button = LCD_BUTTONS_UP;
                }

                if (_debouncedVal > 160 && _debouncedVal < 190) {
                    _button = LCD_BUTTONS_DOWN;
                }

                if (_debouncedVal > 70 && _debouncedVal < 100) {
                    _button = LCD_BUTTONS_BACK;
                }

                if (_debouncedVal > 490 && _debouncedVal < 520) {
                    _button = LCD_BUTTONS_ENTER;
                }

                if (_debouncedVal > 300 && _debouncedVal < 330) {
                    _button = LCD_BUTTONS_MENU;
                }                
            }

            _buttonSamples = 0;
        }
    
        _lastMillis = millis();
    }      
}

byte LCDButtons::getButton() {
    return _button;
}