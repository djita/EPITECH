#include <p18cxxx.h>
#include <i2c.h>
#include "init.h"
#include "liblcd.h"
#include <xlcd.h>

static void _init_thermal_sensor(void)
{
//  SSPCON1 = 0b00101001;
//  IPR1bits.SSPIP = 1;
//  SetPriorityIntI2C1(1);
//  SetPriorityIntI2C2(1);
//  PORTC = 0b00000000;
//  SSPCON1bits.SSPEN = 1;
//  SSPOV .... ????

  DDRCbits.RC3 = 1;
  DDRCbits.RC4 = 1;
  SSPCON1 = 0b00101000;
  SSPSTATbits.SMP = 1;
  SSPADD = 5;
}

static void	_init_analog(void)
{
  ADCON0bits.CHS0 = 0;
  ADCON0bits.CHS1 = 0;
  ADCON0bits.CHS2 = 0;
  ADCON0bits.ADCS1 = 0;
  ADCON0bits.ADCS0 = 1;
  ADCON0bits.ADON = 1;
}

static void      _init_lcd(void)
{
   TRISD = 0b00000000;
   OpenXLCD(FOUR_BIT & LINES_5X7);
   SetDDRamAddr(0x00);
}

void    init_all(void)
{
  _init_thermal_sensor();
  _init_lcd();
  _init_analog();
  TRISB = 0b11110000;
  PORTB = 0x0F;
}
