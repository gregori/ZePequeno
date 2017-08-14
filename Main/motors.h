#include <Arduino.h>
#include "constants.h"

#ifndef MOTORS_H
#define MOTORS_H

void move(float,float);
void stop();
void forward();
void backwards();
void spin(bool);
int speedToPWM(float);

int speedToPWM(float velocity) {
  return int(velocity * maxPWM);
}

void move(float linear, float angular) { // from -1 to 1
  float rightSpeed;
  float leftSpeed;
  if (angular > 0) {
    rightSpeed = linear;
    leftSpeed = constrain(linear - angular, -1, 1);
  }
  else {
    leftSpeed = linear;
    rightSpeed = constrain(linear + angular, -1, 1);
  }
  int rightPWM = speedToPWM(rightSpeed);
  int leftPWM = speedToPWM(leftSpeed);
  bool rightForward = 1 + (rightPWM/abs(rightPWM))/2;
  bool leftForward = 1 + (leftPWM/abs(leftPWM))/2;   
  digitalWrite(rightWheelP1, rightForward);
  digitalWrite(rightWheelP2, not rightForward);
  digitalWrite(leftWheelP1, leftForward);
  digitalWrite(leftWheelP2, not leftForward);
  analogWrite(rightWheelPWM, abs(rightPWM));
  analogWrite(leftWheelPWM, abs(leftPWM));  
}

void stop() {
  move(0,0);
}

void forward() {
  move(1,0);
}

void backwards() {
  move(-1,0);
}

void spin(bool right) {
  if (right) {
    move(0,1);
  }
  else {
    move(0,-1);
  }
}

#endif