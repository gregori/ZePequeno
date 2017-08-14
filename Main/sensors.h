#include <Arduino.h>
#include "constants.h"

#ifndef SENSORS_H
#define SENSORS_H

int lastToSee = -1;

bool readIR(bool);
int readIRs();
bool anyIR();

bool readIR(bool right) {
  if (right) {
    return (digitalRead(rightIR));
  }
  return (digitalRead(leftIR));
}

int readIRs() {
  return readIR(1) - readIR(0);
}

bool anyIR() {
  return (readIR(0) || readIR(1));
}

#endif