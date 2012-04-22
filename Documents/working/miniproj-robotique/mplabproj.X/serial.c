/*
** serial.c for robot_tp in /home/falck_m/Work/robot_tp
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Mon Mar 05 16:09:20 2012 mickael falck
** Last update Mon Mar 05 16:09:25 2012 mickael falck
*/

#include <p18cxxx.h>
#include "serial.h"
#include "type.h"

unsigned char putchar(unsigned char data)
{
  if (tx_buffer.len < BUFFER_LEN)
    {
      tx_buffer.buf[tx_buffer.index_write] = data;
      ++tx_buffer.index_write;
      ++tx_buffer.len;
      PIE1bits.TXIE = 1;
      return (1);
    }
  return (0);
}

unsigned char getchar(unsigned char *data)
{
  if (rx_buffer.len > 0)
    {
      if (BUFFER_LEN == rx_buffer.index_write)
	rx_buffer.index_write = 0;
      if (BUFFER_LEN == rx_buffer.index_read)
	rx_buffer.index_read = 0;
      *data = rx_buffer.buf[rx_buffer.index_read];
      ++rx_buffer.index_read;
      --rx_buffer.len;
      PIE1bits.RCIE = 1;
      return (1);
    }
  return (0);
}

void    serial_write(void)
{
  if (PIE1bits.TXIE && PIR1bits.TXIF)
    {
      if (tx_buffer.len > 0)
	{
	  INTCONbits.PEIE = 0;
	  if (BUFFER_LEN == tx_buffer.index_write)
	    tx_buffer.index_write = 0;
	  if (BUFFER_LEN == tx_buffer.index_read)
	    tx_buffer.index_read = 0;
	  TXREG = tx_buffer.buf[tx_buffer.index_read];
	  --tx_buffer.len;
	  ++tx_buffer.index_read;
	  INTCONbits.PEIE = 1;
	}
      else
        PIE1bits.TXIE = 0;
    }
}

void    serial_read(void)
{
  if (PIR1bits.RCIF && PIE1bits.RCIE)
    {
      if (rx_buffer.len < BUFFER_LEN)
      {
        INTCONbits.PEIE = 0;
        rx_buffer.buf[rx_buffer.index_write] = RCREG;
        ++rx_buffer.len;
        ++rx_buffer.index_write;
        INTCONbits.PEIE = 1;
      }
    }
}
