/*
** xopen.c for xfnc in /home/czegan_g/project/current/corewar/asm/lib/xfnc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 19 14:40:38 2012 louis duverdier
** Last update lun. févr. 20 18:12:56 2012 gaby czegany
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

int	xopen_create(const char *path, int flags, int mode)
{
  int	fd;

  if ((fd = open(path, flags, mode)) < 0)
    {
      my_puterr("Could not open file '");
      my_puterr(path);
      my_puterr("'.\n");
      exit(EXIT_FAILURE);
    }
  return (fd);
}
