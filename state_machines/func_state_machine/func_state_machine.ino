// NOTE: Debounce code is based on the code found at:
//     http://www.arduino.cc/en/Tutorial/Debounce

int ledPin1 = 13; // LED connected to digital pin 13
int ledPin2 = 14; // LED connected to digital pin 14

int buttonPin = 7;   // pushbutton connected to digital pin 7

int buttonState; // the state of the pushbutton
int lastReading = LOW; // initialise the previous reading from the pushbutton

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
    machineState1(); // go to first machine state
}

void loop() {
    // nothing to do in here!
}

void machineState1() {
    while (true) {
        // turn off both LEDs
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        
        if (readButton() == HIGH) {
            digitalWrite(ledPin1, HIGH); // turn on first LED

            machineState2(); // jump to the next state!
        }
    }
}

void machineState2() {
    while (true) {
        if (readButton() == HIGH) {
            digitalWrite(ledPin2, HIGH); // turn on second LED
            
            machineState3(); // jump to the next state!
        }
    }
}

void machineState3() {
    while (true) {
        if (readButton() == HIGH) {
            digitalWrite(ledPin1, LOW); // turn off first LED

            machineState4(); // jump to the next state!
        }
    }
}

void machineState4() {
    while (true) {
        if (readButton() == HIGH) {
            digitalWrite(ledPin2, LOW); // turn off first LED

            machineState1(); // jump to the next state!
        }
    }
}

int readButton() {
    // the following debounce code is based on the code found at:
    //     http://www.arduino.cc/en/Tutorial/Debounce

    // read the current state of the button
    int readButton = digitalRead(buttonPin);

    // check to see if you just pressed the button 
    // (i.e. the input went from LOW to HIGH),  and you've waited 
    // long enough since the last press to ignore any noise:  

    // If the switch changed, due to noise or pressing:
    if (readButton != lastReading) {
        // reset the debouncing timer
        lastDebounceTime = millis();
    } 

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:

        // if the button state has changed:
        if (readButton != buttonState) {
            buttonState = readButton;
        }
    }

    // save the reading.  Next time through the loop,
    // it'll be the lastButtonState:
    lastReading = readButton;

    return buttonState; // return the state of the button
}
