/*
** my_putstr.c for corewar in /home/duverd_l/Documents/Projets/corewar/corewar
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 26 14:16:22 2012 louis duverdier
** Last update Thu Jan 26 16:36:27 2012 louis duverdier
*/

#include <my.h>

static void	_my_write(int fd, const char *str)
{
  xwrite(fd, str, my_strlen(str));
}

void	my_putstr(const char *str)
{
  _my_write(1, str);
}

void	my_puterr(const char *str)
{
  _my_write(2, str);
}
