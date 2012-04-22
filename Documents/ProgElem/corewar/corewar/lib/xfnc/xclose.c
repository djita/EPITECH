/*
** xclose.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Wed Mar 14 16:06:30 2012 louis duverdier
*/

#include "my.h"

void	xclose(int fd)
{
  if (close(fd) < 0)
    my_puterr("Could not close the file. Skipped.\n");
}
