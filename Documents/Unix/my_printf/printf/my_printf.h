/*
** my_printf.h for my_printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 20:35:45 2011 lyoma guillou
** Last update Sat Nov 19 17:52:12 2011 lyoma guillou
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

int	my_putchar(char c);
int	my_put_oct(char *num);
int	my_putoctal(char c, char *base_to);
int	my_putcstr(char *str);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_numlen(unsigned int nb, int base_len);
int     is_num(char c);
int     is_over_int(int nb, char sp);
int	my_getnbr(char *str);
int	my_putunnbr(unsigned nb);
int	my_putnbr(int nb);
int	my_putnbr_base(unsigned int nb, char *base_to, int opt);
int	my_nbr_base(unsigned int x, char opt);
int	modulo_check(va_list ap, char opt);
int	my_printf(const char *format, ...);

#endif
