#include "Joystick.h"
#include "Button.h"


Button btn1(2);
Button btn2(3);
Button btn3(4);
Button btn4(5);

boolean modBtnPressed = false;

void setup() {
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

//  int ax2 = analogRead(A1); //(0 - 1023)
//  int ax2val = map(ax2, 0, 1023, 0, 255);
//  if (ax2val < 5) {
//    Joystick.pressButton(7);
//  } else if (ax2val > 235) {
//    Joystick.pressButton(6);
//  } else {
//    Joystick.releaseButton(6);  
//    Joystick.releaseButton(7); 
//  }
  
}

void onBtn1Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(3);  
  } else {
    Joystick.pressButton(0);  
  }
  
}

void onBtn1UnPress(Button &btn) {
    Joystick.releaseButton(3);  
    Joystick.releaseButton(0);  
}

void onBtn2Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(4);  
  } else {
    Joystick.pressButton(1);  
  }
}

void onBtn2UnPress(Button &btn) {
    Joystick.releaseButton(4);  
    Joystick.releaseButton(1);    
}

void onBtn3Press(Button &btn) {
  if (modBtnPressed) {
    Joystick.pressButton(5);  
  } else {
    Joystick.pressButton(2);  
  }
}

void onBtn3UnPress(Button &btn) {
    Joystick.releaseButton(5);  
    Joystick.releaseButton(2);  
}

void onBtn4Press(Button &btn) {
  modBtnPressed = true;
}

void onBtn4UnPress(Button &btn) {
  modBtnPressed = false;
  
}


