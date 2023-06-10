#include "avr/io.h"
#include "avr/interrupt.h"

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
    pinMode(1, OUTPUT);

    for (int i = 0; i < 10; i++)
    {
        digitalWrite(1, HIGH);
        delay(500);
        digitalWrite(1, LOW);
        delay(500);
    }

    // self destruct
    shred();
}

void loop()
{
}