/*
** xwrite.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Wed Jan 18 16:38:07 2012 louis duverdier
** Last update Wed Jan 18 16:40:05 2012 louis duverdier
*/

#include <unistd.h>
#include <my.h>

void	xwrite(int fd, const char *str, int size)
{
  if (write(fd, str, size) < 0 && fd != 2)
    my_puterr("Warning: cannot perform a write.\n");
}
