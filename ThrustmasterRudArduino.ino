#include "Joystick.h"
#include "Button.h"

#define btn1Pin 2
#define btn2Pin 3
#define btn3Pin 4
#define btn4Pin 5
#define ax1Pin A0
#define ax2Pin A1

Button btn1(btn1Pin);
Button btn2(btn2Pin);
Button btn3(btn3Pin);
Button btn4(btn4Pin);

boolean modBtnPressed = false;

void setup() {
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(btn3Pin, INPUT_PULLUP);
  pinMode(btn4Pin, INPUT_PULLUP);

  pinMode(ax1Pin, INPUT);

  Joystick.begin();
  btn1.setPressHandler(onBtnPress);
  btn1.setUnPressHandler(onBtnUnPress);

  btn2.setPressHandler(onBtnPress);
  btn2.setUnPressHandler(onBtnUnPress);

  btn3.setPressHandler(onBtnPress);
  btn3.setUnPressHandler(onBtnUnPress);

  btn4.setPressHandler(onBtnPress);
  btn4.setUnPressHandler(onBtnUnPress);

  btn4.setPressHandler(onModBtnPress);
  btn4.setUnPressHandler(onModBtnUnPress);

  btn4.setClickHandler(onModBtnClick);
}


void loop() {
  btn1.scan();
  btn2.scan();
  btn3.scan();
  btn4.scan();

  int ax1 = analogRead(ax1Pin); //(20 - 900)
  int ax1val = map(ax1, 20, 900, 255, 0);
  Joystick.setThrottle(ax1val);

  int ax2 = analogRead(ax2Pin); //(0 - 1023)
  if (modBtnPressed) {
    int ax2val = map(ax2, 0, 1023, 360, 0);
    Joystick.setXAxisRotation(ax2val);
    Joystick.setRudder(127);
  } else {
    int ax2val = map(ax2, 0, 1023, 255, 0);
    Joystick.setRudder(ax2val);
    Joystick.setXAxisRotation(180);
  }

}

void onBtnPress(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(btn.getPin() + 1);
  } else {
    Joystick.pressButton(btn.getPin() - 2);
  }

}

void onBtnUnPress(Button &btn) {
  Joystick.releaseButton(btn.getPin() + 1);
  Joystick.releaseButton(btn.getPin() - 2);
}

void onModBtnPress(Button &btn) {
  modBtnPressed = true;
}

void onModBtnUnPress(Button &btn) {
  modBtnPressed = false;
}

void onModBtnClick(Button &btn) {
  Joystick.pressButton(6);
  delay(100);
  Joystick.releaseButton(6);
}


