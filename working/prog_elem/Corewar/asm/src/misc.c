/*
** misc.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Fri Jan 20 11:47:44 2012 louis duverdier
** Last update Mon Jan 23 10:51:31 2012 louis duverdier
*/

#include <asm.h>

int	is_act(const char *d)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (!my_strcmp(op_tab[i].mnemonique, d))
	return (i);
      i += 1;
    }
  return (-1);
}

int	contains(const char *str, char c)
{
  while (*str && *str != c)
    ++str;
  return (*str == c);
}
