/*
** xopen.c for xfnc in /home/czegan_g/work/school/corewar/asm/lib/xfnc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 19 14:40:38 2012 louis duverdier
** Last update sam. mars 24 16:39:38 2012 gaby czegany
*/

# include       <my.h>

int	xopen(const char *path, int flags)
{
  int	fd;

  fd = open(path, flags);
  if (fd < 0)
  {
    my_puterr("Error: Could not open file '");
    my_puterr(path);
    my_puterr("'.\nExit...\n");
    exit(EXIT_FAILURE);
  }
  return (fd);
}

int	xopen_create(const char *path, int flags, int mode)
{
  int	fd;

  fd = open(path, flags, mode);
  if (fd < 0)
  {
    my_puterr("Error: Could not open file '");
    my_puterr(path);
    my_puterr("'.\nExit...\n");
    exit(EXIT_FAILURE);
  }
  return (fd);
}
