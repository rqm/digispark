#include "DigiKeyboard.h"

void setup()
{
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // open run
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    // obfuscation via cmd and hidden powershell option
    DigiKeyboard.print("cmd /c start /min \"\" powershell -WindowStyle Hidden ");
    DigiKeyboard.delay(100);
    // run script
    DigiKeyboard.print("Msg $env:username 'hello world'");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}