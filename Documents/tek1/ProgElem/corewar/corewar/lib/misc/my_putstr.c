/*
** my_putstr.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Mar 15 12:45:57 2012 louis duverdier
*/

#include "my.h"

static void	_my_write(int fd, const char *str)
{
  int		len;

  len = my_strlen(str);
  if (len > 0)
    xwrite(fd, str, len);
}

void	my_putstr(const char *str)
{
  _my_write(1, str);
}

void	my_puterr(const char *str)
{
  _my_write(2, str);
}

void		my_err(int nbr, ...)
{
  int		i;
  va_list	va;
  char		*value;

  i = 0;
  va_start(va, nbr);
  while (i < nbr)
    {
      value = va_arg(va, char *);
      my_puterr(value);
      ++i;
    }
}
