/*
** my_putchar.c for my_printf in /home/guillo_e//working/test/printf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 10 18:53:40 2011 lyoma guillou
** Last update Mon Nov 14 11:27:04 2011 lyoma guillou
*/

#include <unistd.h>
#include "my_printf.h"

int	my_putchar(char c)
{
  int	i;

  i = write(1, &c, 1);
  return (i);
}
