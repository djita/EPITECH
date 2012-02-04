/*
** xopen.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 14:40:38 2012 louis duverdier
** Last update Thu Jan 19 14:42:28 2012 louis duverdier
*/

#include <my.h>

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
