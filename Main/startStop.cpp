#include <Arduino.h>
#include "startStop.h"
#include "constants.h"
#include "motors.h"

Button button1(button);
SoftwareSerial bluetooth(9, 10);

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
    if (bluetooth.read() == 0) {
      while(true) {}
    }
  }
}

void waitButton() {
  while (1) {
    if (button1.pressed()) {
      break;
    }
  }
  }

void verifyToStopButton() {
  if (button1.pressed()) {
    while(1){
      stop();
      }
  }
}
  