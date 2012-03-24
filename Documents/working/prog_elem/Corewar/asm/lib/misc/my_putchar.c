/*
** my_putchar.c for misc in /home/czegan_g/project/current/corewar/asm/lib/misc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 16:40:56 2012 louis duverdier
** Last update ven. mars 23 00:35:08 2012 gaby czegany
*/

# include       <my.h>

void	my_putchar(char c)
{
  xwrite(1, &c, 1);
}

void	my_putchar_fd(int fd, char c)
{
  xwrite(fd, &c, 1);
}
