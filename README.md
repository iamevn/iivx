# Notes
- For [Arduino Leonardo](https://www.arduino.cc/en/main/arduinoBoardLeonardo) boards (authentic or clones)
- Does not require external power to the Arduino board
- Modified for 1000Hz polling rate
- Supports HID (default) and Reactive light control
- **leoo** supports up to 9 buttons (pop'n music, DanceDanceRevolution, and StepMania)
- This is a personal fork; see the main [iivx](https://github.com/Espionage724/iivx) project for use moslty with pop'n
- Add system button or change code before uploading to change light control (see [leoo.ino](leoo/leoo.ino#L12)

# How To Use
- [Download the code archive](https://github.com/iamevn/iivx/archive/master.zip) and extract it
- [Acquire Arduino IDE](https://www.arduino.cc/Main/Software) (must be version 1.6.8 or newer) and start it
- Select **Arduino Leonardo** as your board in Arduino IDE (Tools -> Board)
- Select the COM Port that your board is using (Tools -> Port)
- Select the sketch (File -> Open -> either **iivx-master/leoo/leoo.ino**
- Upload the sketch to your board (Sketch -> Upload)
- Disconnect the board from your computer and implement it into your controller
- Connect the completed controller to the computer being used for games
- Bind controls for the games you want to play

# To swap lighting modes with SYS button:
- Hold SYS button for 3 seconds
- Buttons 1-3 will light up solid
- Buttons 4-6 will blink
- Buttons 7-9 will be unlit
- Press a solidly lit button to enable reactive lighting
- Press a blinking button to enable HID lighting
- Press an unlit button to disable lighting
- If SYS has a light, it will light up/blink/go dark to match the current mode
- Release SYS to exit mode change

# Assumptions
- One board for pop'n music with 9 buttons and lights
- Optional SYS button for switching modes
- SYS button optionally has light which is only lit reactively

# Pins
- There are 3 separate **GND** pins that all function as ground
- All Buttons share a **GND** pin
- All Lights share a **GND** pin
- Lights require resistors, and some pre-assembled arcade button kits come with resistors soldered on already (check inside plastic light housing)

## pop'n music
- Top-row buttons left-to-right are 2, 4, 6, and 8
- Bottom-row buttons left-to-right are 1, 3, 5, 7, and 9
- SYS button optional
- SYS button light optional

### SYS Button (Optional)
- Pin **1**
- Pin **GND**

### SYS Light (Optional)
- Pin **0**
- Pin **GND** (resistor)

### Left White Button 1
- Pin **13**
- Pin **GND**

#### Left White Light
- Pin **12**
- Pin **GND** (resistor)

### Left Yellow Button 2
- Pin **6**
- Pin **GND**

#### Left Yellow Light
- Pin **5**
- Pin **GND** (resistor)

### Left Green Button 3
- Pin **11**
- Pin **GND**

#### Left Green Light
- Pin **10**
- Pin **GND** (resistor)

### Left Blue Button 4
- Pin **A3**
- Pin **GND**

#### Left Blue Light
- Pin **4**
- Pin **GND** (resistor)

### Center Red Button 5
- Pin **A0**
- Pin **GND**

#### Center Red Light
- Pin **9**
- Pin **GND** (resistor)

### Right Blue Button 6
- Pin **A4**
- Pin **GND**

#### Right Blue Light
- Pin **3**
- Pin **GND** (resistor)

### Right Green Button 7
- Pin **A1**
- Pin **GND**

#### Right Green Light
- Pin **8**
- Pin **GND** (resistor)

### Right Yellow Button 8
- Pin **A5**
- Pin **GND**

#### Right Yellow Light
- Pin **2**
- Pin **GND** (resistor)

### Right White Button 9
- Pin **A2**
- Pin **GND**

#### Right White Light
- Pin **7**
- Pin **GND** (resistor)
