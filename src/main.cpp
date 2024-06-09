#include "keys.h"
#include <Arduino.h>
void setup() { Serial.begin(9600); }
void loop() {
  while (Serial.available() == 0)
    ;
  String datos = Serial.readString();
  int marca, codigo;
  sscanf(datos.c_str(), "%d,%d", &marca, &codigo);
  Serial.println("1: " + String(marca) + " Tecla: " + String(codigo));
  if (marca == 101) {
    Serial.println("Marca: Samsung");
  } else if (marca == 102) {
    Serial.println("Marca: Sony");
  };
  Serial.println("Codigo: " + enviarSenal(marca, codigo));
}
