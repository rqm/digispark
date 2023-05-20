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
    // open terminal via spotlight
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    // hello world
    DigiKeyboard.print("echo 'hello world'");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    // quit terminal
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
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