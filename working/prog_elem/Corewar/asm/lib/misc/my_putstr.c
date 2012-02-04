/*
** my_putstr.c for asm in /home/duverd_l/
** 
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
** 
** Started on  Fri Jan 20 10:44:05 2012 louis duverdier
** Last update Fri Jan 20 10:44:06 2012 louis duverdier
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
