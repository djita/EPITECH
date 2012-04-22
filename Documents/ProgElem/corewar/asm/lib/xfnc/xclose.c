/*
** xclose.c for xfnc in /home/czegan_g/project/current/corewar/asm/lib/xfnc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Thu Jan 19 14:40:38 2012 louis duverdier
** Last update ven. mars 23 00:35:24 2012 gaby czegany
*/

# include       <my.h>

void	xclose(int fd)
{
  if (close(fd) < 0)
    my_puterr("Could not close the file. Skipped.\n");
}
