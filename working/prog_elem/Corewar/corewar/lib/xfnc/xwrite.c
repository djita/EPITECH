/*
** xwrite.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:35:46 2012 louis duverdier
*/

#include <unistd.h>
#include <my.h>

void	xwrite(int fd, const char *str, int size)
{
  if (write(fd, str, size) < 0 && fd != 2)
    my_puterr("Warning: cannot perform a write.\n");
}
