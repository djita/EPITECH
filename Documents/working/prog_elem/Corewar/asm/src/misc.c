/*
** misc.c for src in /home/czegan_g/project/current/corewar/asm/src
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 11:47:44 2012 louis duverdier
** Last update mar. févr. 14 07:18:03 2012 gaby czegany
*/

#include <asm.h>

int	get_param(int type)
{
  type = type & T_LAB ? type ^ T_LAB : type;
  if (type & T_REG)
    return (V_REG);
  if (type & T_DIR)
    return (V_DIR);
  if (type & T_IND)
    return (V_DIR);
  return (0);
}

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
