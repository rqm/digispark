# Digispark BadUSB
Digispark BadUSB scripts, headers, bootloader

## Bootloader
- `upgrade-attiny85_jumper.hex` → jumper bootloader without 5s delay (to enter the bootloader and upload user program, short P0 to GND with a jumper wire) 

## Header files
- `DigiKeyboard.h` → full keyboard support
- `usbconfig.h` → updated VID/PID pair for Apple keyboard (to emulate a different vendor/device, use https://devicehunt.com)

## Scripts
Windows and macOS BadUSB scripts for the Digispark

- obfuscation (screen brightness, hidden windows)
- erase history (bash, run)
- reverse shell