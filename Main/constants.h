#include <Arduino.h>

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define led 0
#define leftWheelPWM 20
#define rightWheelPWM 21
#define leftWheelP1 15
#define leftWheelP2 14
#define rightWheelP1 18
#define rightWheelP2 19
#define leftIR 10
#define rightIR 9
#define receptor 5

#define maxPWM 200

#define SWITCH_ONE             4
#define SWITCH_TWO             3
#define SWITCH_THREE           2
#define SWITCH_FOUR            1

void initialSet() {
  pinMode(led, OUTPUT);
  pinMode(leftWheelPWM, OUTPUT);
  pinMode(rightWheelPWM, OUTPUT);
  pinMode(leftWheelP1, OUTPUT);
  pinMode(rightWheelP1, OUTPUT);
  pinMode(leftWheelP2, OUTPUT);
  pinMode(rightWheelP2, OUTPUT);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  pinMode(receptor, INPUT);
  pinMode(SWITCH_ONE, INPUT);
  pinMode(SWITCH_TWO, INPUT);
  pinMode(SWITCH_THREE, INPUT);
  pinMode(SWITCH_FOUR, INPUT);
  
  digitalWrite(led, 1);
}

#endif