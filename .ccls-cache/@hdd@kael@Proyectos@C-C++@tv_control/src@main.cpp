#include "keys.h"
#include <Arduino.h>
void setup() { Serial.begin(9600); }
void loop() {
  while (Serial.available() == 0) {
  }
  int marca = Serial.parseInt();
  Serial.println("Escribiste: " + String(marca));
  enviarSenal(marca, POWEROFF);
}
