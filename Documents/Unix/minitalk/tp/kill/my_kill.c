/*
** my_kill.c for my_kill in /home/guillo_e//Documents/working/unix/minitalk/tp
~** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:59:43 2012 lyoma guillou
** Last update Thu Mar 15 17:54:54 2012 lyoma guillou
*/

#define _POSIX_SOURCE
#define _BSD_SOURCE

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int		main(int ac, char **av)
{
  int		pid;
  int		i;
  char		c;

  i = 0;
  ac = ac;
  pid = atoi(av[1]);
  c = 'c';
  while (i < 8)
    {
      usleep(1500);
      if (c & (1 << (7 - i)))
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      ++i;
    }
  c = 0;
  while (i < 8)
    {
      usleep(1500);
      if (c & (1 << (7 - i)))
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      ++i;
    }
  return (0);
}