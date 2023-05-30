#include "DigiKeyboard.h"

void setup()
{
    // hello world
    String script = "echo 'hello world'";
    String scriptLines = "1";
    // reset
    DigiKeyboard.sendKeyStroke(0);
    // open terminal via spotlight
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(2000);
    // run script
    DigiKeyboard.print(script);
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    // erase history
    DigiKeyboard.print("sed -i '' \"$(($(wc -l <$HISTFILE)-" + scriptLines + ")),$ d\" $HISTFILE");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    // quit terminal
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
}

void loop()
{
}