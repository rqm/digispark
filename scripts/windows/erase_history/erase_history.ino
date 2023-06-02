#include "DigiKeyboard.h"

void setup()
{
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // open run
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    // run script
    DigiKeyboard.print("powershell Msg $env:username 'hello world';");
    DigiKeyboard.delay(100);
    // erase run history
    DigiKeyboard.print("Remove-ItemProperty -Path HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU -Name *");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}