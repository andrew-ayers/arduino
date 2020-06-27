# LCD Menu Operations #

### About ###

This document describes both the layout of the LCD menu and the operational states for the tester. It should not be considered definitive - errors may exist!

### Initialization ###

```
1. DC power applied - POWER ON

2. Arduino initializes itself and LCD:

    a. Sets MOSFET to LOW - 12VDC output OFF
    b. Sets indicator LED to LOW (off)
    c. Clears LCD
    d. Sets {mode} to "Initialized"

3. Displays MODE: {mode} at top of LCD

    a. Displays reading of current sensor (scale per settings)
    b. Displays reading of voltage sensor (in volts)

4. Potential MODE settings:

    a. Initialized (false mode - only at startup)
    b. Power Supply
    c. Motor Testing
    d. Servo Testing
    e. ESC Testing
    f. Settings

5. Mode/Navigation selection buttons:

        U
        |
    L---S---R
        |
        D

    U / D = Up / Down
    L / R = Left / Right
        S = Select    

6. When U/D buttons are pressed, MODE is displayed (b-f)

    a. U => f...e...d...c...b...f...(cont)
       D => b...c...d...e...f...b...(cont)

    b. If mode is not selected by pressing the S (select) button within 5 
       seconds, mode will return to the last selected mode and settings

    c. D advances selection, U decrements selection, S button selects
```

### Post-initialization - MODE 6 - Power Supply ###

```
    +----------------------------------------+
    | Power Supply |    VOLTS    |  CURRENT  |
    |              |             |           |
    |      OFF     |    12.1     |  0.1A     |
    |              |             |           |
    +----------------------------------------+

    a. Default to OFF

        * Sets MOSFET to LOW - 12VDC output OFF
        * Sets indicator LED to LOW (off)

    b. Pressing S button toggles between ON and OFF

    c. When set to ON:

        * Sets MOSFET to HIGH - 12VDC output ON
        * Sets indicator LED to HIGH (on)

    d. When set to ON or OFF:

        * Displays reading of current sensor (scale per settings)
        * Displays reading of voltage sensor (in volts)

NOTE: If any button is pressed at any time during a test in MODEs 7-9,
      switch to OFF status, and return to MODE selection.
```

### MODE 7 - Motor Testing ###

```
    Selection (U/D choose, S button selects, L exits):
    +----------------------------------------+
    |  Motor Test  |    VOLTS    |  CURRENT  |
    |     30s      |             |           |
    |  > Cancel    |    12.1     |  0.1A     |
    |    Start     |             |           |
    +----------------------------------------+

    Testing:
    +----------------------------------------+
    |  Motor Test  |    VOLTS    |  CURRENT  |
    |     27s      |             |           |
    |   1021 RPM   |    12.1     |  0.1A     |
    |     37c      |             |           |
    +----------------------------------------+

    Completed (U/D scrolls up/down, L exits):
    +----------------------------------------+
    | Motor Test |TEMP| RPM  | VOLTS | CURR  |
    |    STALL   | 38 | 0    | 12    | 9.8A  |
    |   AVERAGE  | 42 | 1000 | 12.0  | 0.8A  |
    |     MIN    | 36 | 980  | 11.8  | 0.7A  |
    |     MAX    | 50 | 1005 | 12.4  | 1.2A  |
    +----------------------------------------+

    a. Default to OFF

        * Sets MOSFET to LOW - 12VDC output OFF
        * Sets indicator LED to LOW (off)

    b. Select Test Length (1s, 5s, 15s, 30s, 60s, 300s, 600s)

    c. Select Start or Cancel (default = Cancel)

    d. If Cancel is selected, return to MODE selection
    
    e. If Start is selected:

        * Begin countdown
        * When countdown reaches zero (0), start test process
        * Monitor: Voltage, Current and RPM
        * Based on update rate, output logging to GLCD, and if USB logging is 
          ON, output logging to USB
        * Note: Update rate might have to be high (ie - smaller than smallest
          rate?) at the beginning, and slow to set rate, or some other method
          may be needed - in order to capture dead-start (stall condition)
          current measurement. Need to research this.
        * If soft-start is selected, PWM easing the MOSFET at selected rate
          from zero (0) to 255 (ON) and hold; otherwise just turn the MOSFET
          to HIGH
        * Count for test length at update rate
        * If soft-start is selected, PWM easing the MOSFET at selected rate
          from 255 (ON) to zero (0) and hold; otherwise just turn the MOSFET
          to LOW

    f. When the test ends - default to OFF

        * Sets MOSFET to LOW - 12VDC output OFF
        * Sets indicator LED to LOW (off)
        * Display averages and max/min:

            * Voltage
            * Current
            * Temperature
            * RPM
```

### MODE 8 - Servo Testing ###

```
    Selection (U/D choose, S button selects, L exits):
    +----------------------------------------+
    |  Servo Test  |    VOLTS    |  CURRENT  |
    |  > MANUAL    |             |           |
    |    OSCLT NE  |    12.1     |  0.1A     |
    |    OSCLT WE  |             |           |
    |    CANCEL    |             |           |
    +----------------------------------------+

    a. Sets MOSFET to LOW - 12VDC output OFF
    b. Sets indicator LED to LOW (off)
    c. Select one of:

        * Manual (L/R controls position output)
        * Oscillate (No Easing)
        * Oscillate (With Easing)

    d. Monitor: Voltage and Current
     
        * Based on update rate, output logging to GLCD, and if USB logging is 
          ON, output logging to USB
```

### MODE 9 - ESC Testing ###

```
    Selection (U/D choose, S button selects, L exits):
    +----------------------------------------+
    |   ESC Test   |    VOLTS    |  CURRENT  |
    | > MANUAL     |    12.1     |  0.1A     |
    |   OSCLT NE   |    RPM      |  TEMP     |
    |   OSCLT WE   |    1001     |  37C      |
    |   CANCEL     |             |           |
    +----------------------------------------+

    a. Sets MOSFET to HIGH - 12VDC output ON
    b. Sets indicator LED to HIGH (on)
    c. Select one of:

        * Manual (L/R controls position output)
        * Oscillate (No Easing)
        * Oscillate (With Easing)

    d. Monitor: Voltage, Current, RPM, Temperature
     
        * Based on update rate, output logging to GLCD, and if USB logging is 
          ON, output logging to USB
```

### MODE 10 - Settings ###

```
    Selection:
    
        1. U/D scrolls up/down
        2. S button selects
        3. L exits

    +----------------------------------------+
    |                Settings                |
    | > Update Rate                      2s  |
    |   Soft Start Easing                Yes |
    |   End Test on Error                Yes |
    |   Servo/ESC Easing Speed           5   |
    |   Log to USB                       Yes |
    |   CANCEL                               |
    +----------------------------------------+

    Update:
    
        1. U/D shows options
        2. S button selects
        3. L exits

    +----------------------------------------+
    |                Settings                |
    |   Update Rate                    > 2s  |
    |   Soft Start Easing                Yes |
    |   End Test on Error                Yes |
    |   Servo/ESC Easing Speed           5   |
    |   Log to USB                       Yes |
    |   CANCEL                               |
    +----------------------------------------+

    a. Monitor update rate (0.25s, 0.5s, 1s, 2s, 5s, 10s)
    
    b. Soft Start/Stop (on/off)

        Note: Update rate, plus test length, plus ??? may prevent proper working
        of a soft start/stop easing 
    
    c. End Test on Error (yes/no)?

    Update (yes/no):
    +----------------------------------------+
    |                Settings                |
    |   Update Rate                      2s  |
    |   Soft Start Easing                Yes |
    |   End Test on Error              > Yes |
    |   Servo/ESC Easing Speed           5   |
    |   Log to USB                       Yes |
    |   CANCEL                               |
    +----------------------------------------+

    If "End Test on Error" is "Yes" and S button is pressed, then show:

    Selection:
    
        1. U/D scrolls up/down
        2. S button selects
        3. L exits

    +----------------------------------------+
    |             Error Settings             |
    | > Voltage (delta % V)          3%      |
    |   Current (delta % mA)         8%      |
    |   RPM (delta %)                10%     |
    |   Temperature (delta % C)      5%      |
    |   Over-current                 9500 mA |
    |   Over-temperature             45C     |
    |   CANCEL                               |
    +----------------------------------------+

    Update:
    
        1. U/D shows options
        2. S button selects
        3. L exits

    +----------------------------------------+
    |             Error Settings             |
    |   Voltage (delta % V)          3%      |
    |   Current (delta % mA)         8%      |
    |   RPM (delta %)                10%     |
    |   Temperature (delta % C)    > 5%      |
    |   Over-current                 9500 mA |
    |   Over-temperature             45C     |
    |   CANCEL                               |
    +----------------------------------------+

        * Error on Voltage (delta % V)
        * Error on Current (delta % mA)
        * Error on RPM (delta % R)
        * Error on Temperature (delta % C)
        * Error on Over-current (set max mA)
        * Error on Over-temperature (set max C)
    
    d. (Servo/ESC) Easing Speed (1-10)
    
    e. Log to USB (yes/no)
```

### USB Logging ###

```
USB Log packet format:

"START",{MODE}

    {0001},{Voltage},{Current},{RPM},{Temperature}
    ...
    {000n},{Voltage},{Current},{RPM},{Temperature}

"STOP",{MODE}
   
    or

"CANCEL",{MODE}

    or (if enabled)

"ERROR",{MODE},{Description}
```

### Who do I cuss out? ###

If you notice any discrepancies or issues with this project, or if you just want to send me a love letter (or hate mail):

* Andrew L. Ayers - andrewa AT phoenixgarage DOT org [ [www.phoenixgarage.org](https://www.phoenixgarage.org/) ]