#include "keys.h"
#include <Arduino.h>
#include <IRremote.hpp>
#define DELAY_AFTER_SEND 2000
#define DELAY_AFTER_LOOP 5000
#define DISABLE_CODE_FOR_RECEIVER
#define IR_RECEIVE_PIN 2
// #define IR_SEND_PIN 3
#define TONE_PIN 4
#define APPLICATION_PIN 5
#define ALTERNATIVE_IR_FEEDBACK_LED_PIN 6

String enviarSenalSamsung(int tecla);
String enviarSenalSony(int tecla);

String enviarSenal(int marca, int numTecla) {
  if (marca == 101) {
    IrSender.setSendPin(3);
    String codigoSamsung = enviarSenalSamsung(numTecla);
    Serial.println("Ejecutado");
    return codigoSamsung;
  } else if (marca == 102) {
    IrSender.setSendPin(5);
    String codigoSony = enviarSenalSony(numTecla);
    Serial.println("Ejecutado");
    return codigoSony;
  }
}
String enviarSenalSamsung(int tecla) {
  switch (tecla) {
  case 1:
    // Power Off
    IrSender.sendSamsung(0x707, 0x2, 3);
    return "Power Off";
  case 2:
    // Up
    IrSender.sendSamsung(0x707, 0x60, 3);
    return "Up";
  case 3:
    // Right
    IrSender.sendSamsung(0x707, 0x62, 3);
    return "Right";
  case 4:
    // Left
    IrSender.sendSamsung(0x707, 0x65, 3);
    return "Left";
  case 5:
    // Down
    IrSender.sendSamsung(0x707, 0x61, 3);
    return "Down";
  case 6:
    // Enter
    IrSender.sendSamsung(0x707, 0x68, 3);
    return "Enter";
  case 7:
    // Mute
    IrSender.sendSamsung(0x707, 0xF, 3);
    return "Mute";
  case 8:
    // Ch +
    IrSender.sendSamsung(0x707, 0x12, 3);
    return "Ch +";
  case 9:
    // Ch -
    IrSender.sendSamsung(0x707, 0x10, 3);
    return "Ch -";
  case 10:
    // Vol +
    IrSender.sendSamsung(0x707, 0x7, 3);
    return "Vol +";
  case 11:
    // Vol -
    IrSender.sendSamsung(0x707, 0xB, 3);
    return "Vol -";
  case 12:
    // Source
    IrSender.sendSamsung(0x707, 0x1, 3);
    return "Source";
  case 13:
    // Menu
    IrSender.sendSamsung(0x707, 0x1A, 3);
    return "Menu";
  case 14:
    // Tools
    IrSender.sendSamsung(0x707, 0x4B, 3);
    return "Tools";
  case 15:
    // Return
    IrSender.sendSamsung(0x707, 0x58, 3);
    return "Return";
  case 16:
    // Info
    IrSender.sendSamsung(0x707, 0x1F, 3);
    return "Info";
  case 17:
    // Exit
    IrSender.sendSamsung(0x707, 0x2D, 3);
    return "Exit";
  case 18:
    // 1
    IrSender.sendSamsung(0x707, 0x4, 3);
    return "1";
  case 19:
    // 2
    IrSender.sendSamsung(0x707, 0x5, 3);
    return "2";
  case 20:
    // 3
    IrSender.sendSamsung(0x707, 0x6, 3);
    return "3";
  case 21:
    // 4
    IrSender.sendSamsung(0x707, 0x8, 3);
    return "4";
  case 22:
    // 5
    IrSender.sendSamsung(0x707, 0x9, 3);
    return "5";
  case 23:
    // 6
    IrSender.sendSamsung(0x707, 0xA, 3);
    return "6";
  case 24:
    // 7
    IrSender.sendSamsung(0x707, 0xC, 3);
    return "7";
  case 25:
    // 8
    IrSender.sendSamsung(0x707, 0xD, 3);
    return "8";
  case 26:
    // 9
    IrSender.sendSamsung(0x707, 0xE, 3);
    return "9";
  case 27:
    // 0
    IrSender.sendSamsung(0x707, 0x11, 3);
    return "0";

  default:
    return "No se encontro la tecla";
  }
}

String enviarSenalSony(int tecla) {
  switch (tecla) {
  case 1:
    // Power Off
    IrSender.sendSony(0x1, 0x15, 3, 12);
    return "Power Off";
  case 2:
    // Top
    IrSender.sendSony(0x1, 0x74, 3, 12);
    return "Top";
  case 3:
    // Rigth
    IrSender.sendSony(0x1, 0x33, 3, 12);
    return "Rigth";
  case 4:
    // Left
    IrSender.sendSony(0x1, 0x34, 3, 12);
    return "Left";
  case 5:
    // Bottom
    IrSender.sendSony(0x1, 0x75, 3, 12);
    return "Bottom";
  case 6:
    // Enter
    IrSender.sendSony(0x1, 0x65, 3, 12);
    return "Enter";
  case 7:
    // Mute
    IrSender.sendSony(0x1, 0x14, 3, 12);
    return "Mute";
  case 8:
    // Ch +
    IrSender.sendSony(0x1, 0x10, 3, 12);
    return "Ch +";
  case 9:
    // Ch -
    IrSender.sendSony(0x1, 0x11, 3, 12);
    return "Ch -";
  case 10:
    // Vol +
    IrSender.sendSony(0x1, 0x12, 3, 12);
    return "Vol +";
  case 11:
    // Vol -
    IrSender.sendSony(0x1, 0x13, 3, 12);
    return "Vol -";
  case 12:
    // Source
    IrSender.sendSony(0x1, 0x25, 3, 12);
    return "Source";
  case 13:
    // Menu no es
    IrSender.sendSony(0x1, 0x65, 3, 12);
    return "Menu";
  case 14:
    // Tools
    IrSender.sendSony(0x97, 0x36, 3, 15);
    return "Tools";
  case 15:
    // Return
    IrSender.sendSony(0x97, 0x23, 3, 15);
    return "Return";
  case 16:
    // Info
    IrSender.sendSony(0x1A, 0x7B, 3, 15);
    return "Info";
  case 17:
    // Exit
    IrSender.sendSony(0x1, 0x63, 3, 12);
    return "Exit";
  case 18:
    // 1
    IrSender.sendSony(0x1, 0x0, 3, 12);
    return "1";
  case 19:
    // 2
    IrSender.sendSony(0x1, 0x1, 3, 12);
    return "2";
  case 20:
    // 3
    IrSender.sendSony(0x1, 0x2, 3, 12);
    return "3";
  case 21:
    // 4
    IrSender.sendSony(0x1, 0x3, 3, 12);
    return "4";
  case 22:
    // 5
    IrSender.sendSony(0x1, 0x4, 3, 12);
    return "5";
  case 23:
    // 6
    IrSender.sendSony(0x1, 0x5, 3, 12);
    return "6";
  case 24:
    // 7
    IrSender.sendSony(0x1, 0x6, 3, 12);
    return "7";
  case 25:
    // 8
    IrSender.sendSony(0x1, 0x7, 3, 12);
    return "8";
  case 26:
    // 9
    IrSender.sendSony(0x1, 0x8, 3, 12);
    return "9";
  case 27:
    // 0
    IrSender.sendSony(0x1, 0x9, 3, 12);
    return "0";
  default:
    return "No se encontro la tecla";
  }
}
