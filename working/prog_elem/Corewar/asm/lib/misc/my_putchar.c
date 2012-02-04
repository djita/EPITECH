/*
** my_putchar.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 16:40:56 2012 louis duverdier
** Last update Wed Jan 18 16:41:10 2012 louis duverdier
*/

#include <my.h>

void	my_putchar(char c)
{
  xwrite(1, &c, 1);
}
