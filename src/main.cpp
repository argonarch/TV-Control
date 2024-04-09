#include "keys.h"
#include <Arduino.h>
void setup() { Serial.begin(9600); }
void loop() {
  while (Serial.available() == 0) {
  }
  int marca = Serial.parseInt();
  int codigo = Serial.parseInt();
  Serial.println("Escribiste: " + String(marca) +
                 ", Codigo: " + String(codigo));
  enviarSenal(marca, codigo);
}
