/*
** pty_funcs.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar  2 22:00:22 2013 Lyoma Guillou
** Last update Sun Mar  3 19:25:51 2013 Lyoma Guillou
*/

#include "my_script.h"

int		my_unlockpt(int fd)
{
  int		null;

  null = 0;
  return (ioctl(fd, TIOCSPTLCK, &null));
}

int		my_grantpt(int fd)
{
  return (fchmod(fd, 0620));
}

char		*my_ptsname(int fd)
{
  unsigned int	pty_num;
  static char	buff[16];

  if (ioctl(fd, TIOCGPTN, &pty_num) != 0)
    return NULL;
  snprintf(buff, sizeof(buff),"/dev/pts/%u", pty_num);
  return (buff);
}
