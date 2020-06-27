# Arduino Pin Usage Reference #

### 4-bit LCD control (ANET LCD2004) ###

https://www.instructables.com/id/Step-By-Step-LCD-wiring-4-Bit-Mode-and-Programmi/

### LCD Control ###

Pin 4 on the LCD to Digital IO 6 on the Arduino
Pin 6 on the LCD to Digital IO 7 on the Arduino

### LCD Data ###

Pin 11 on the LCD to Digital IO 9 on the Arduino
Pin 12 on the LCD to Digital IO 10 on the Arduino
Pin 13 on the LCD to Digital IO 11 on the Arduino
Pin 14 on the LCD to Digital IO 12 on the Arduino

---

Buttons (ANET LCD2004) to an analog pin A2

---

https://create.arduino.cc/projecthub/instrumentation-system/acs712-current-sensor-87b4a6

Current sensor (ACS712 30A) to an analog pin A0

Voltage sensor (DIYmall 0-25v) to an analog pin A1

---

RPM sensor (photodetector) to digital pin D2

https://forum.arduino.cc/index.php?topic=436337.0
http://arduinoprojects101.com/arduino-rpm-counter-tachometer/
https://learn.sparkfun.com/tutorials/qrd1114-optical-detector-hookup-guide/all

---

https://www.amazon.com/Non-Contact-Infrared-Temperature-Algorithms-interface/dp/B07V52M45H/

#### Temperature sensor (Maiji OTI-301) to I2C? ####

Pin A4 to SDA
Pin A5 to SCL

## !!! URGENT !!! Sensor Vdd to 3.3V on Arduino !!! ##

I2C address = 0x20
Read 6 bytes via I2C, divide by 200 for temperature value (C or F?)

Not same sensor - but may help?

https://create.arduino.cc/projecthub/SurtrTech/contactless-temperature-sensor-mlx90614-1e7bc7

---

Code (https://electronics.stackexchange.com/questions/466546/oti-301-infrared-sensor):

```
// Demo Arduino code for the OPT-301 non-contact thermometer
// References used:
//   https://drive.google.com/file/d/1XMRDCNzY3fn0q6lkGejs5D-pqksfRuZ8/view?usp=sharing
//   https://drive.google.com/file/d/1mmdkHkNbwC5VgQxGMrq07XolajNvgBkN/view?usp=sharing

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  const int addr = 0x10; // I2C addresses at 7-bit, must shift documented 0x20 address, so 0x10.

  Wire.beginTransmission(addr);
  Wire.write(0x80);
  int rv = Wire.endTransmission(false);

  if (rv != 0) {
    Serial.print("Error while transmitting: ");
    Serial.println(rv);
  } else {
    const int n = 6;
    uint8_t dat[n];

    Wire.requestFrom(addr, n);

    int i;
    for (i = 0; i < n && Wire.available(); i++) {
      dat[i] = Wire.read();
    }

    if (i != n) {
      Serial.println("Incomplete data");
    } else {
      float amb = (dat[2] * 65536L + dat[1] * 256L + dat[0]) / 200.;
      float obj = (dat[5] * 65536L + dat[4] * 256L + dat[3]) / 200.;

      Serial.print("Temperatures (C): Ambient: ");
      Serial.print(amb);
      Serial.print("  Object: ");
      Serial.println(obj);
    }
  }
}
```
---

Pins D0 and D1 for USB usage (no connections!)

Need 2 digital outputs, both PWM capable

Pins 3, 5, 6, 9, 10, 11: See https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

---

1. Output to MOSFET control (DGZZI 5-36V 400W MOSFET module)

   Control voltage output to motor

   Use digital pin D3

   https://forum.arduino.cc/index.php?topic=492633.0
   http://www.aosmd.com/pdfs/datasheet/AOD4184A.pdf
   https://robojax.com/learn/arduino/?vid=robojax-e-Switch-AOD4184A
   https://protosupplies.com/product/d4184-mosfet-control-module/

   https://forum.arduino.cc/index.php?topic=473269.0

   https://www.amazon.com/Anmbest-High-Power-Adjustment-Electronic-Brightness/dp/B07NWD8W26/

   Diode on output for inductive/pwm loads?

   GND O --->|--- O +V motor

2. Output for servo signal for ESC or servo:

   https://www.arduino.cc/en/reference/servo

   Use digital pin D5

---

Use digital pin D13 for status LED

---

```
D0 = USB RX
D1 = USB TX
D2 = Phototransistor (RPM)
D3 = MOSFET (output voltage PWM)
D4 = n/c
D5 = Servo Control

D6-D7 = LCD Control

D8 = n/c

D9-D12 = LCD 4-bit data

D13 = Status LED

A0 = Current Sensor (ACS712)
A1 = Voltage Sensor
A2 = LCD Buttons
A3 = n/c
A4 = SDA (I2C Temperature Sensor OTI-301)
A5 = SCL (I2C Temperature Sensor OTI-301)
```

### Who do I cuss out? ###

If you notice any discrepancies or issues with this project, or if you just want to send me a love letter (or hate mail):

* Andrew L. Ayers - andrewa AT phoenixgarage DOT org [ [www.phoenixgarage.org](https://www.phoenixgarage.org/) ]