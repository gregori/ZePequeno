#include <Arduino.h>
#include "constants.h"
#include "motors.h"

#ifndef STARTSTOP_H
#define STARTSTOP_H

void waitBluetooth() {
  bool ready = false;
  while (not ready) {
    if (bluetooth.available() > 0) {
      ready = (bluetooth.read() == 1);
    }
  }
}

void verifyToStopBluetooth() {
  if (bluetooth.available() > 0) {
    if bluetooth.read() == 0 {
      while(true) {}
    }
  }
}

void waitButton() {
    while (not digitalRead(button)) {}
  }

void verifyToStopButton() {
  if (digitalRead(button)) {
    while(true) {}
  }
}
  

#endif