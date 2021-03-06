# ANET LCD2004 and Buttons - Module, Schematic, and Pinouts #

## Module ##

![ANET LCD 2004](LCD2004.jpg)

## Schematic ##

![ANET LCD 2004 Schematic](LCD2004-schematic.png)

## Board (back) Pinouts ##

### LCD Pin Order ###

[ 16 . . . . . . . 8 . . . . . . 1 ]

### IDC Male Connector ###

  * Pin 1 (Bottom Left)
  * Pin 5 (Bottom Right)
  * Pin 6 (Top Right)
  * Pin 10 (Top Left)
``` 
+-----------------+ 
| 10  9  8  7  6  |
|  1  2  3  4  5  |
+------+   +------+ 

IDC Male Connector Pin

 1 = Ground     (LCD Pin 1 and 16 - VSS, and Buttons - Arduino GND)
 2 = NC
 3 = RS         (LCD Pin 4 - Arduino D6)
 4 = E          (LCD Pin 6 - Arduino D7)
 5 = Buttons    (Arduino A2)
 6 = D7         (LCD Pin 14 - Arduino D12)
 7 = D6         (LCD Pin 13 - Arduino D11)
 8 = D5         (LCD Pin 12 - Arduino D10)
 9 = D4         (LCD Pin 11 - Arduino D9)
10 = VCC        (LCD Pin 2 - VDD, and Buttons - Arduino 5V)
```

### IDC Female Connector (Ribbon) ###

  * Pin 1 (Bottom Right)
  * Pin 5 (Bottom Left)
  * Pin 6 (Top Left)
  * Pin 10 (Top Right)

```
+-----------------+
|  6  7  8  9  10 |
|  5  4  3  2  1  |
+------+   +------+
       +---+

 1 = Ground     (LCD Pin 1 and 16 - VSS, and Buttons - Arduino GND)
 2 = NC
 3 = RS         (LCD Pin 4 - Arduino D6)
 4 = E          (LCD Pin 6 - Arduino D7)
 5 = Buttons    (Arduino A2)
 6 = D7         (LCD Pin 14 - Arduino D12)
 7 = D6         (LCD Pin 13 - Arduino D11)
 8 = D5         (LCD Pin 12 - Arduino D10)
 9 = D4         (LCD Pin 11 - Arduino D9)
10 = VCC        (LCD Pin 2 - VDD, and Buttons - Arduino 5V)
```

### ANET LCD 2004 Arduino Interface Schematic ###

![ANET LCD 2004 Arduino Interface Schematic](LCD2004-arduino-interface-schematic.png)

```
Color Legend:

VDD / 5V  = Red
VSS / Gnd = Black
Buttons   = Green
RS / E    = Yellow (control)
D4 - D7   = Blue (data)
```

### Additional References ###

[Arduino Pin Usage Reference](../general/pins.md)

### Who do I cuss out? ###

If you notice any discrepancies or issues with this project, or if you just want to send me a love letter (or hate mail):

* Andrew L. Ayers - andrewa AT phoenixgarage DOT org [ [www.phoenixgarage.org](https://www.phoenixgarage.org/) ]