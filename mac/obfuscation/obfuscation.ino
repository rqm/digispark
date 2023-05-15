#include "DigiKeyboard.h"

void setup()
{
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // screen obfuscation ON
    for (int i = 0; i < 16; i++)
    {
        DigiKeyboard.sendKeyStroke(KEY_F1);
    }
    // hello world
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("Hello world!");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ESCAPE);
    DigiKeyboard.sendKeyStroke(KEY_ESCAPE);
    // screen obfuscation OFF
    for (int i = 0; i < 16; i++)
    {
        DigiKeyboard.sendKeyStroke(KEY_F2);
    }
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}