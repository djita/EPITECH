/*
** xwrite.c for xfnc in /home/czegan_g/project/current/corewar/asm/lib/xfnc
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Wed Jan 18 16:38:07 2012 louis duverdier
** Last update ven. mars 23 00:35:32 2012 gaby czegany
*/

# include       <unistd.h>
# include       <my.h>

void	xwrite(int fd, const char *str, int size)
{
  if (write(fd, str, size) < 0 && fd != 2)
    my_puterr("Warning: cannot perform a write.\n");
}
