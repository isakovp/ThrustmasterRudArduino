#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "Button.h"


Button btn1(2);
Button btn2(3);
Button btn3(4);
Button btn4(5);

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  Joystick.begin();
  btn1.setPressHandler(onBtn1Press);
  btn1.setUnPressHandler(onBtn1UnPress);

  btn2.setPressHandler(onBtn2Press);
  btn2.setUnPressHandler(onBtn2UnPress);

  btn3.setPressHandler(onBtn3Press);
  btn3.setUnPressHandler(onBtn3UnPress);

  btn4.setPressHandler(onBtn4Press);
  btn4.setUnPressHandler(onBtn4UnPress);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}


void loop() {
  
 btn1.scan();
 btn2.scan();
 btn3.scan();
 btn4.scan();

 int ax1 = analogRead(A0); //(20 - 900)
 int ax1val = map(ax1, 20, 900, 0, 255);
 Joystick.setThrottle(255 - ax1val);

// int ax2 = analogRead(A1); //(0 - 1023)
// Serial.println(ax2);
// int ax2val = map(ax2, 0, 1023, 0, 255);
// Joystick.setRudder(255 - ax2val);

 total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(A1);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;

  int ax2val = map(average, 0, 1023, 0, 255);
  //Joystick.setRudder(255 - ax2val);
}

void onBtn1Press(Button &btn) {
 Joystick.pressButton(0);
}

void onBtn1UnPress(Button &btn) {
 Joystick.releaseButton(0);
}

void onBtn2Press(Button &btn) {
 Joystick.pressButton(1);
}

void onBtn2UnPress(Button &btn) {
 Joystick.releaseButton(1);
}

void onBtn3Press(Button &btn) {
 Joystick.pressButton(2);
}

void onBtn3UnPress(Button &btn) {
 Joystick.releaseButton(2);
}

void onBtn4Press(Button &btn) {
 Joystick.pressButton(3);
}

void onBtn4UnPress(Button &btn) {
 Joystick.releaseButton(3);
}


