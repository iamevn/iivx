# Notes
- For [Arduino Leonardo](https://www.arduino.cc/en/main/arduinoBoardLeonardo) boards (authentic or clones)
- Does not require external power to the Arduino board
- Modified for 1000Hz polling rate
- Supports HID and Reactive light control
- **leoo** supports up to 9 buttons (pop'n music, DanceDanceRevolution, and StepMania)
- **leovxhq** supports up to 7 buttons and 2 high-quality encoders (SOUND VOLTEX and K-Shoot MANIA)
- Add system button or change code before uploading to change light control (see [leoo.ino](leoo/leoo.ino) or [leovxhq.ino](leovxhq/leovxhq.ino))

# How To Use
- Select **Arduino Leonardo** as your board in Arduino IDE
- Select the COM Port that your board is using
- Select the sketch you want (either **leo.ino** or **leovxhq.ino**)
- Upload the sketch to your board
- Disconnect the board from your computer and implement it into your controller
- Connect the completed controller to the computer being used for games
- Bind controls for the games you want to play

# Assumptions
- One board for SOUND VOLTEX and/or K-Shoot MANIA with 7 buttons, 7 lights, and 2 encoders
- One board for DanceDanceRevolution and/or StepMania with no lights and only 4 panels/buttons
- One board for pop'n music with 9 buttons and lights

# Pins
- There are 3 separate **GND** pins that all function as ground
- All Buttons share a **GND** pin
- All Lights share a **GND** pin
- Lights require resistors, and some pre-assembled arcade button kits come with resistors soldered on already (check inside plastic light housing)

## Shortcuts
- [SOUND VOLTEX](#sound-voltex)
- [DanceDanceRevolution](#dancedancerevolution)
- [pop'n music](#popn-music)

## SOUND VOLTEX
- Both Analogs share a **GND** and **5V** pin

### VOL-L Analog
- Pin **0** (white)
- Pin **1** (green)
- Pin **GND** (black)
- Pin **5V** (red)

### VOL-R Analog
- Pin **2** (white)
- Pin **3** (green)
- Pin **GND** (black)
- Pin **5V** (red)

### Start
- Pin **13**
- Pin **GND**

#### Start Light
- Pin **6**
- Pin **GND** (resistor)

### Button A
- Pin **A0**
- Pin **GND**

#### Button A Light
- Pin **7**
- Pin **GND** (resistor)

### Button B
- Pin **A1**
- Pin **GND**

#### Button B Light
- Pin **8**
- Pin **GND** (resistor)

### Button C
- Pin **A2**
- Pin **GND**

#### Button C Light
- Pin **9**
- Pin **GND** (resistor)

### Button D
- Pin **A3**
- Pin **GND**

#### Button D Light
- Pin **10**
- Pin **GND** (resistor)

### FX-L
- Pin **A4**
- Pin **GND**

#### FX-L Light
- Pin **11**
- Pin **GND** (resistor)

### FX-R
- Pin **A5**
- Pin **GND**

#### FX-R Light
- Pin **12**
- Pin **GND** (resistor)

## DanceDanceRevolution

### P1 Up
- Pin **11**
- Pin **GND**

### P1 Down
- Pin **12**
- Pin **GND**

### P1 Left
- Pin **13**
- Pin **GND**

### P1 Right
- Pin **A0**
- Pin **GND**

## pop'n music
- Top-row buttons left-to-right are 2, 4, 6, and 8
- Bottom-row buttons left-to-right are 1, 3, 5, 7, and 9

### Left White Button 1
- Pin **11**
- Pin **GND**

#### Left White Light
- Pin **1**
- Pin **GND** (resistor)

### Left Yellow Button 2
- Pin **12**
- Pin **GND**

#### Left Yellow Light
- Pin **2**
- Pin **GND** (resistor)

### Left Green Button 3
- Pin **13**
- Pin **GND**

#### Left Green Light
- Pin **3**
- Pin **GND** (resistor)

### Left Blue Button 4
- Pin **A0**
- Pin **GND**

#### Left Blue Light
- Pin **4**
- Pin **GND** (resistor)

### Center Red Button 5
- Pin **A1**
- Pin **GND**

#### Center Red Light
- Pin **5**
- Pin **GND** (resistor)

### Right Blue Button 6
- Pin **A2**
- Pin **GND**

#### Right Blue Light
- Pin **6**
- Pin **GND** (resistor)

### Right Green Button 7
- Pin **A3**
- Pin **GND**

#### Right Green Light
- Pin **7**
- Pin **GND** (resistor)

### Right Yellow Button 8
- Pin **A4**
- Pin **GND**

#### Right Yellow Light
- Pin **8**
- Pin **GND** (resistor)

### Right White Button 9
- Pin **A5**
- Pin **GND**

#### Right White Light
- Pin **9**
- Pin **GND** (resistor)
