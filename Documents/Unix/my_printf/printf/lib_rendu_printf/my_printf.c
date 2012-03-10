/*
** main.c for printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Nov  9 22:06:07 2011 lyoma guillou
** Last update Sat Nov 19 18:03:19 2011 lyoma guillou
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"

int		my_nbr_base(unsigned int x, char opt)
{
  int		i;

  i = 0;
  if (opt == 'b')
    i = my_putnbr_base(x, "01", 0);
  if (opt == 'o')
    i = my_putnbr_base(x, "01234567", 0);
  if (opt == 'u')
    i = my_putunnbr(x);
  if (opt == 'x')
    i = my_putnbr_base(x, "0123456789abcdef", 0);
  if (opt == 'X')
    i = my_putnbr_base(x, "0123456789ABCDEF", 0);
  return (i);
}

int		modulo_check(va_list ap, char opt)
{
  int		len;

  len = 0;
  if (opt == 'd' || opt == 'i')
    len = my_putnbr(va_arg(ap, int));
  if (opt == 'o' || opt == 'u' || opt == 'x' || opt == 'X' || opt == 'b')
    len = my_nbr_base(va_arg(ap, unsigned int), opt);
  if (opt == 'c')
    len = my_putchar(va_arg(ap, int));
  if (opt == 'p')
    {
      len = my_putstr("0x");
      len = len + my_putnbr_base(va_arg(ap, unsigned long int), "0123456789abcdef", 0);
    }
  if (opt == 's')
    len = my_putstr(va_arg(ap, char *));
  if (opt == 'S')
    len = my_putcstr(va_arg(ap, char *));
  if (opt == '%')
    len = my_putchar('%');
  return (len);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		ind;
  int		i;

  i = 0;
  ind = 0;
  va_start(ap, format);
  while (format[i])
    {
      if (format[i] == '%')
	{
	  i = i + 1;
	  ind = ind + modulo_check(ap, format[i]);
	}
      else
	ind = ind + my_putchar(format[i]);
      i++;
    }
  va_end(ap);
  return (ind);
}
