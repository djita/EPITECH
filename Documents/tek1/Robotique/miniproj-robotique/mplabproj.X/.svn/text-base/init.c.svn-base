#include <p18cxxx.h>
#include <i2c.h>
#include "init.h"
#include "liblcd.h"
#include <xlcd.h>
#include "type.h"


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

void	init_serial()
{
  TRISCbits.TRISC6 = 0;
  TRISCbits.TRISC7 = 1;

  SPBRG = 25;

  RCSTAbits.SPEN = 1;
  
  TXSTAbits.BRGH = 1;
  TXSTAbits.SYNC = 0;  
  TXSTAbits.TX9 = 0;
  TXSTAbits.TXEN = 1;

  IPR1bits.TXIP = 0;

  RCONbits.IPEN = 1;
  PIE1bits.TXIE = 1;
  INTCONbits.GIEH = 1;
  INTCONbits.GIEL = 1;
}

void    init_all(void)
{
  _init_thermal_sensor();
  _init_lcd();
  _init_analog();
  init_serial();
  TRISB = 0b11110000;
  PORTB = 0x0F;
}
