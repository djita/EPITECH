/*
** xclose.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Thu Jan 19 14:40:38 2012 louis duverdier
** Last update Thu Jan 19 18:53:42 2012 louis duverdier
*/

#include <my.h>

void	xclose(int fd)
{
  if (close(fd) < 0)
    my_puterr("Could not close the file. Skipped.\n");
}
