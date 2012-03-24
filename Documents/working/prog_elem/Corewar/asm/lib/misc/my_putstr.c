/*
** my_putstr.c for misc in /home/czegan_g/project/current/corewar/asm/lib/misc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 10:44:05 2012 louis duverdier
** Last update ven. mars 23 00:34:59 2012 gaby czegany
*/

# include       <my.h>

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
