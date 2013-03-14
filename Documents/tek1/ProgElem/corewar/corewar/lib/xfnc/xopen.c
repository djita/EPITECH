/*
** xopen.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Wed Mar 14 16:06:36 2012 louis duverdier
*/

#include "my.h"

int	xopen(const char *path, int flags)
{
  int	fd;

  if ((fd = open(path, flags)) < 0)
    {
      my_puterr("Could not open file '");
      my_puterr(path);
      my_puterr("'.\n");
      exit(EXIT_FAILURE);
    }
  return (fd);
}
