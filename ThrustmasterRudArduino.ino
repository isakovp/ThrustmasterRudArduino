#include "Joystick.h"
#include "Button.h"


Button btn1(2);
Button btn2(3);
Button btn3(4);
Button btn4(5);

boolean modBtnPressed = false;

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
}


void loop() {

  btn1.scan();
  btn2.scan();
  btn3.scan();
  btn4.scan();

  int ax1 = analogRead(A0); //(20 - 900)
  int ax1val = map(ax1, 20, 900, 0, 255);
  Joystick.setThrottle(255 - ax1val);
}

void onBtn1Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(3);  
  } else {
    Joystick.pressButton(0);  
  }
  
}

void onBtn1UnPress(Button &btn) {
  if (modBtnPressed) {
    Joystick.releaseButton(3);  
  } else {
    Joystick.releaseButton(0);  
  }
  modBtnPressed = false;
}

void onBtn2Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(4);  
  } else {
    Joystick.pressButton(1);  
  }
}

void onBtn2UnPress(Button &btn) {
  if (modBtnPressed) {
    Joystick.releaseButton(4);  
  } else {
    Joystick.releaseButton(1);  
  }
  modBtnPressed = false;
}

void onBtn3Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(5);  
  } else {
    Joystick.pressButton(2);  
  }
}

void onBtn3UnPress(Button &btn) {
  if (modBtnPressed) {
    Joystick.releaseButton(5);  
  } else {
    Joystick.releaseButton(2);  
  }
  modBtnPressed = false;
}

void onBtn4Press(Button &btn) {
  Joystick.releaseButton(0); 
  Joystick.releaseButton(1); 
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
  Joystick.releaseButton(4);
  Joystick.releaseButton(5); 
  modBtnPressed = true;
}

void onBtn4UnPress(Button &btn) {
  Joystick.releaseButton(0); 
  Joystick.releaseButton(1); 
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
  Joystick.releaseButton(4);
  Joystick.releaseButton(5); 
  modBtnPressed = false;
  
}


