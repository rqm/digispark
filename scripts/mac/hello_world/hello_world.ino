#include "DigiKeyboard.h"

void setup()
{
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // hello world
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("Hello world!");
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}