#include "iivx_leo.h"
iivxReport_t report;

#define REPORT_DELAY 1000
//#define REPORT_DELAY 2000
// Number of microseconds between HID reports
// 1000 = 1000hz (modified)
// 2000 = 500hz (leoo default)

int tmp;
// variables for state change
uint8_t state = 0;
// 0 = normal operation, 1 = SYS held before lighting change mode, 2 = lighting change mode
unsigned long sysHoldTime;
const unsigned long sysHoldDelay = 3000; // ms
const unsigned long blinkDelay = 750; // ms

// variables for buttons/pins
const uint8_t buttonCount = 9;
uint8_t lightMode = 1;
// 0 = reactive lighting, 1 = HID lighting, 2 = no lighting
// HID lighting is supported for bemanitools with pop'n music
// Reactive lighting activates lights on button-press, regardless of the game (StepMania, LR2)
// No lighting disables button lights entirely
const uint8_t ledPins[] = {12, 5, 10, 4, 9, 3, 8, 2, 7};
const uint8_t buttonPins[] = {13, 6, 11, 21, 18, 22, 19, 23, 20};
const uint8_t sysLight = 0;
const uint8_t sysButton = 1;
/* current pin layout
 *  pins 12, 5, 10, 4, 9, 3, 8, 2, 7 = LED 1 to 9
 *    connect pin to + terminal of LED
 *    connect ground to resistor and then - terminal of LED
 *      (note: many arcade lights have resistor built in)
 *  pins 13, 6, 11, 21, 18, 22, 19, 23, 20 = Button input 1 to 9
 *    connect button pin to ground to trigger button press
 *
 *  pins 0 = system LED
 *    connect pin to + terminal of LED
 *    connect ground to resistor and then - terminal of LED
 *      (note: many arcade lights have resistor built in)
 *  pins 1 = system pin
 *    connect system pin to ground to trigger lighting mode change
 */

void lights(uint16_t lightDesc) {
  for (int i = 0; i < buttonCount; i++) {
     if ((lightDesc >> i) & 1) {
         digitalWrite(ledPins[i], HIGH);
     } else {
         digitalWrite(ledPins[i],LOW);
     }
  }
}

void setup() {
  delay(1000);
  // Setup I/O for pins
  for (int i = 0; i < buttonCount; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(sysButton, INPUT_PULLUP);
  pinMode(sysLight, OUTPUT);
}

void loop() {
  // Read buttons
  for (int i = 0; i < buttonCount; i++) {
    if (digitalRead(buttonPins[i]) != HIGH) {
      report.buttons |= (uint16_t)1 << i;
    } else {
      report.buttons &= ~((uint16_t)1 << i);
    }
  }

  switch (state) {
    case 0:
      normalMode();
      break;
    case 1:
      interMode();
      break;
    case 2:
      changeMode();
      break;
  }

  // Send report and delay
  iivx.setState(&report);
  delayMicroseconds(REPORT_DELAY);
}

void normalMode() {
  // Light LEDs
  switch (lightMode) {
    case 0:
      lights(report.buttons);
      break;
    case 1:
      lights(iivx_led);
      break;
    case 2:
      lights(0);
      break;
  }

  // Detect state change
  // change to interMode if SYS is pressed
  if (digitalRead(sysButton) == LOW) {
    state = 1;
    sysHoldTime = millis();
  }
}

void interMode() {
  // Light LEDs
  switch (lightMode) {
    case 0:
      lights(report.buttons);
      break;
    case 1:
      lights(iivx_led);
      break;
    case 2:
      lights(0);
      break;
  }

  // Detect state change
  // change to normalMode if SYS is released
  // change to changeMode after sysHoldDelay milliseconds
  if (digitalRead(sysButton) == HIGH) {
    state = 0;
  } else if (millis() - sysHoldTime >= sysHoldDelay) {
    state = 2;
  }
}

void changeMode() {
  uint16_t lightDesc;
  uint16_t change = 0;
  // detect lightMode change
  // buttons 1-3
  if (report.buttons & 07) change |= 1;
  // buttons 4-6
  if (report.buttons & 070) change |= 2;
  // buttons 7-9
  if (report.buttons & 0700) change |= 4;

  // change light mode if only one mode chosen
  switch (change) {
    case 1:
      lightMode = 0;
      break;
    case 2:
      lightMode = 1;
      break;
    case 4:
      lightMode = 2;
      break;
  }

  // Light LEDs
  // option 1
  // buttons 1-3 are on, buttons 4-6 blink, buttons 7-9 are off
  // cycle between 0b000000111 and 0b000111111
  if (millis() % (blinkDelay * 2) < blinkDelay) {
    lightDesc = 07;
    if (lightMode == 1) digitalWrite(sysLight, LOW);
  } else {
    lightDesc = 077;
    if (lightMode == 1) digitalWrite(sysLight, HIGH);
  }
  if (lightMode == 0) digitalWrite(sysLight, HIGH);
  if (lightMode == 2) digitalWrite(sysLight, LOW);
  lights(lightDesc);

  // option 2
  /*
  // button 4 is on, button 5 blinks, button 6 is off
  // buttons 1-3, 7-9 light/blink/nolight depending on lightMode
  // cycle between 0b000110000 and 0b000100000
  if (millis() % (blinkDelay * 2) < blinkDelay) {
    lightDesc = 040;
    if (lightMode == 1) digitalWrite(sysLight, LOW);
  } else {
    if (lightMode == 1) {
      digitalWrite(sysLight, HIGH);
      // 0b111110111
      lightDesc = 0767;
    } else {
      lightDesc = 060;
    }
  }
  if (lightMode == 0) {
    digitalWrite(sysLight, HIGH);
    lightDesc |= 0707;
  }
  if (lightMode == 2) digitalWrite(sysLight, LOW);
  lights(lightDesc);
   */

  // Detect state change
  // change to normalMode if SYS is released
  if (digitalRead(sysButton) == HIGH) {
    state = 0;
  }
}
