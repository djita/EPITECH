/*
** my_putchar.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:35 2012 louis duverdier
*/

#include <my.h>

void	my_putchar(char c)
{
  xwrite(1, &c, 1);
}
