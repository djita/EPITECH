/*
** my_putchar.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Wed Mar 14 16:06:10 2012 louis duverdier
*/

#include "my.h"

void	my_putchar(char c)
{
  xwrite(1, &c, 1);
}
