#include <p18cxxx.h>
#include <i2c.h>
#include <stdio.h>
#include <stdlib.h>
#include "liblcd.h"
#include "graph.h"

#define adrtc74 0b1001101
#define regtemp 0
#define config 1

void    job_lcd(char temp, unsigned char analog_int, unsigned char analog_float)
{
    static int i = 0;
    char    mybuff[16];

    sprintf(mybuff, (const far rom char*)"Temp = %d Deg", temp);
    lcd_putram(mybuff, 0, 0);
    sprintf(mybuff, (const far rom char*)"Analog = %d.%d   ", analog_int, alalog_float);
    lcd_putram(mybuff, 1, 0);
    i += 1;
}

static char _ack(void)
{
  while(SSPSTATbits.R_W);
  while(SSPCON2bits.ACKSTAT);
}

static char _read_thermal(unsigned char adresse, unsigned char registre)
{
  char t;
  // SSPSR => SSPBUF P128
  // P130
  // 
  SSPCON2bits.SEN = 1;
  while (SSPCON2bits.SEN);
  SSPBUF = adresse << 1;
  _ack();
  SSPBUF = registre;
  _ack();
  SSPCON2bits.RSEN = 1;
  while (SSPCON2bits.RSEN);
  SSPBUF = (adresse << 1) | 0b00000001;
  _ack();
  SSPCON2bits.RCEN = 1;
  while (SSPCON2bits.RCEN);
  t = SSPBUF;
  SSPCON2bits.ACKDT = 1;
  SSPCON2bits.ACKEN = 1;
  while (SSPCON2bits.ACKEN);
  SSPCON2bits.PEN = 1;
  while (SSPCON2bits.PEN);
  return t;
}

char	job_thermal(void)
{
  char t;

  t = 0;
  while (!((t = _read_thermal(adrtc74, config)) & 0b01000000));
  t = _read_thermal(adrtc74, regtemp);
  if (t & 0b10000000)
    {
      t = ~t;
      t = -t;
    }
  //add_point_to_graph(t, &deg_graph);
  return (t);
}

void	job_analog(void)
{
  // DELAY
  ADCON0bits.GO_DONE = 1;
  while (ADCON0bits.GO_DONE);
}

static char	_celcius_to_faranit(char celcius)
{
  return (9.0 / 5.0) celcius + 32;
}

static unsigned char	_int_to_volt(unsigned char c)
{
  return c / 51;
}

static unsigned char	_float_to_volt(unsigned char c)
{
  return 255 / c;
}

void    job(void)
{
    char    t;

    t = job_thermal();
    job_analog();
    if (boobool == true)
      job_lcd(_celcius_to_faranit(t), ADRESH, 0);
    else
      job_lcd(t, _int_to_volt(ADRESH), _float_to_volt(ADRESL));
    //    PORTB = PORTD;
}