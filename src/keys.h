#include <Arduino.h>
#define POWEROFF 1
#define UP 2
#define RIGHT 3
#define LEFT 4
#define DOWN 5
#define ENTER 6
#define MUTE 7
#define CH_UP 8
#define CH_DOWN 9
#define VOL_UP 10
#define VOL_DOWN 11
#define SOURCE 12
#define MENU 13
#define TOOLS 14
#define RETURN 15
#define INFO 16
#define EXIT 17
#define NUM_1 18
#define NUM_2 1U
#define NUM_3 20
#define NUM_4 21
#define NUM_5 22
#define NUM_6 23
#define NUM_7 24
#define NUM_8 25
#define NUM_9 26
#define NUM_0 27

#define SAMSUNG_M 101
#define SONY_M 102
String enviarSenal(int marca, int numTecla);
