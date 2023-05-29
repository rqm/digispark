#include "DigiKeyboard.h"

void setup()
{
    // hello world
    String script = "Msg $env:username 'hello world'";
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // open cmd via run,
    // launching a hidden powershell
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("cmd /c start /min \"\" powershell -WindowStyle Hidden " + script);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}