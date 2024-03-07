#include <Arduino.h>
#include <IRremote.hpp>
#include "PinDefinitionsAndMore.h"

void enviarSenalSamsung(int tecla);
void enviarSenalSony(int tecla);

void setup(){
    Serial.begin(9600);
}

void loop(){
    if (Serial.available() != 0) {
        Serial.readString();
    }
    if (IrReceiver.decode()) {
        // Print a short summary of received data
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.printIRSendUsage(&Serial);
        Serial.println();

        /*
         * Here data is available -> evaluate IR command
         */
        switch (IrReceiver.decodedIRData.command) {
        case 0x47: // The play key on the bottom of my Samsung remote
            Serial.println(F("Play key detected, open Netflix"));
            enviarSenalSamsung(12);
            break;

        case 0x4A: // The pause key on the bottom of my Samsung remote
            Serial.println(F("Pause key detected, open SmartHub"));
            enviarSenalSony(12);
            break;

        default:
            break;
        }

        /*
         * !!!Important!!! Enable receiving of the next value,
         * since receiving has stopped after the end of the current received data packet.
         */
        IrReceiver.restartAfterSend(); // Is a NOP if sending does not require a timer.
        IrReceiver.resume(); // Enable receiving of the next value
    }
    
    delay(5000);
}

void enviarSenalSamsung(int tecla)
{
    switch (tecla)
    {
    case 1:
        // Power Off
        IrSender.sendSamsung(0x707, 0x2, 1);
        break;
    case 2:
        // Top
        IrSender.sendSamsung(0x707, 0x60, 1);
        break;
    case 3:
        // Rigth
        IrSender.sendSamsung(0x707, 0x62, 1);
        break;
    case 4:
        // Left
        IrSender.sendSamsung(0x707, 0x65, 1);
        break;
    case 5:
        // Bootom
        IrSender.sendSamsung(0x707, 0x61, 1);
        break;
    case 6:
        // Enter
        IrSender.sendSamsung(0x707, 0x68, 1);
        break;
    case 7:
        // Mute
        IrSender.sendSamsung(0x707, 0xF, 1);
        break;
    case 8:
        // Ch +
        IrSender.sendSamsung(0x707, 0x12, 1);
        break;
    case 9:
        // Ch -
        IrSender.sendSamsung(0x707, 0x10, 1);
        break;
    case 10:
        // Vol +
        IrSender.sendSamsung(0x707, 0x7, 1);
        break;
    case 11:
        // Vol -
        IrSender.sendSamsung(0x707, 0xB, 1);
        break;
    case 12:
        // Source
        IrSender.sendSamsung(0x707, 0x1, 1);
        break;
    case 13:
        // Menu
        IrSender.sendSamsung(0x707, 0x1A, 1);
        break;
    case 14:
        // Tools
        IrSender.sendSamsung(0x707, 0x4B, 1);
        break;
    case 15:
        // Return
        IrSender.sendSamsung(0x707, 0x58, 1);
        break;
    case 16:
        // Info
        IrSender.sendSamsung(0x707, 0x1F, 1);
        break;
    case 17:
        // Exit
        IrSender.sendSamsung(0x707, 0x2D, 1);
        break;
    case 18:
        // 1
        IrSender.sendSamsung(0x707, 0x4, 1);
        break;
    case 19:
        // 2
        IrSender.sendSamsung(0x707, 0x5, 1);
        break;
    case 20:
        // 3
        IrSender.sendSamsung(0x707, 0x6, 1);
        break;
    case 21:
        // 4
        IrSender.sendSamsung(0x707, 0x8, 1);
        break;
    case 22:
        // 5
        IrSender.sendSamsung(0x707, 0x9, 1);
        break;
    case 23:
        // 6
        IrSender.sendSamsung(0x707, 0xA, 1);
        break;
    case 24:
        // 7
        IrSender.sendSamsung(0x707, 0xC, 1);
        break;
    case 25:
        // 8
        IrSender.sendSamsung(0x707, 0xD, 1);
        break;
    case 26:
        // 9
        IrSender.sendSamsung(0x707, 0xE, 1);
        break;
    case 27:
        // 0
        IrSender.sendSamsung(0x707, 0x11, 1);
        break;

    default:
        break;
    }
}

void enviarSenalSony(int tecla)
{
    switch (tecla)
    {
    case 1:
        // Power Off
        IrSender.sendSony(0x1, 0x15, 2, 12);
        break;
    case 2:
        // Top
        IrSender.sendSony(0x1, 0x74, 2, 12);
        break;
    case 3:
        // Rigth
        IrSender.sendSony(0x1, 0x33, 2, 12);
        break;
    case 4:
        // Left
        IrSender.sendSony(0x1, 0x34, 2, 12);
        break;
    case 5:
        // Bootom
        IrSender.sendSony(0x1, 0x75, 2, 12);
        break;
    case 6:
        // Enter
        IrSender.sendSony(0x1, 0x65, 2, 12);
        break;
    case 7:
        // Mute
        IrSender.sendSony(0x1, 0x14, 2, 12);
        break;
    case 8:
        // Ch +
        IrSender.sendSony(0x1, 0x10, 2, 12);
        break;
    case 9:
        // Ch -
        IrSender.sendSony(0x1, 0x11, 2, 12);
        break;
    case 10:
        // Vol +
        IrSender.sendSony(0x1, 0x12, 2, 12);
        break;
    case 11:
        // Vol -
        IrSender.sendSony(0x1, 0x13, 2, 12);
        break;
    case 12:
        // Source
        IrSender.sendSony(0x1, 0x25, 2, 12);
        break;
    case 13:
        // Menu no es
        IrSender.sendSony(0x1, 0x65, 2, 12);
        break;
    case 14:
        // Tools
        IrSender.sendSony(0x97, 0x36, 2, 15);
        break;
    case 15:
        // Return
        IrSender.sendSony(0x97, 0x23, 2, 15);
        break;
    case 16:
        // Info
        IrSender.sendSony(0x1A, 0x7B, 2, 15);
        break;
    case 17:
        // Exit
        IrSender.sendSony(0x1, 0x63, 2, 12);
        break;
    case 18:
        // 1
        IrSender.sendSony(0x1, 0x0, 2, 12);
        break;
    case 19:
        // 2
        IrSender.sendSony(0x1, 0x1, 2, 12);
        break;
    case 20:
        // 3
        IrSender.sendSony(0x1, 0x2, 2, 12);
        break;
    case 21:
        // 4
        IrSender.sendSony(0x1, 0x3, 2, 12);
        break;
    case 22:
        // 5
        IrSender.sendSony(0x1, 0x4, 2, 12);
        break;
    case 23:
        // 6
        IrSender.sendSony(0x1, 0x5, 2, 12);
        break;
    case 24:
        // 7
        IrSender.sendSony(0x1, 0x6, 2, 12);
        break;
    case 25:
        // 8
        IrSender.sendSony(0x1, 0x7, 2, 12);
        break;
    case 26:
        // 9
        IrSender.sendSony(0x1, 0x8, 2, 12);
        break;
    case 27:
        // 0
        IrSender.sendSony(0x1, 0x9, 2, 12);
        break;
    default:
        break;
    }
}