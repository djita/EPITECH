/*
** my_forktty.c for my_forktty.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Fri Feb 25 14:39:05 2011 dimitri doyen
** Last update Sun Mar  3 02:35:22 2013 Lyoma Guillou
*/

#include "my_script.h"

int             my_forkpty(int *amaster, char *name, struct termios *termp,
                           struct winsize *winp)
{
  int           pid;
  int           fd_slave;

  if (my_openpty(amaster, &fd_slave, name, termp, winp) == -1)
    exit(write(2, "openpty\n", 9));
  if ((pid = fork()) < 0)
    return (-1);
  else if (pid == 0)
    {
      my_login_tty(fd_slave);
      return (0);
    }
  else
    {
      close(fd_slave);
      return (pid);
    }
  return (-1);
}
