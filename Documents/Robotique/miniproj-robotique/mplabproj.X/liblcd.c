#include "xlcd.h"
#include <string.h>
#include <delays.h>
#define         buflen(str) strlen(str) - 1

void    delay(int ms)
{
    int i;
    int max;

    i = 0;
    max = 4000 * ms;
    while (i < 0x200)
        ++i;
}

void DelayPORXLCD(void)
{
    Delay1KTCYx(15);
}

void DelayFor18TCY(void)
{
    Delay10TCYx(2);
}

void DelayXLCD(void)
{
    Delay1KTCYx(20);
}

int lcd_putram(char *buffer, int line, int col)
{
   char addr;

   addr = (line % 2) * 0x40;
   SetDDRamAddr(addr + buflen(buffer) + col);  // positionne le curseur en x,y
   putsXLCD(buffer);  // écrit une chaine mémorisée en ROM
}

int lcd_putrom(const rom char *buffer, int line, int col, int len)
{
   char addr;

   addr = (line % 2) * 0x40;
   SetDDRamAddr(addr + (len - 1) + col);  // positionne le curseur en x,y
   putrsXLCD(buffer);  // écrit une chaine mémorisée en ROM
}