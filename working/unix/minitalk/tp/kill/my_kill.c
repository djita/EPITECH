/*
** my_kill.c for my_kill in /home/guillo_e//Documents/working/unix/minitalk/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:59:43 2012 lyoma guillou
** Last update Thu Mar  8 15:20:29 2012 lyoma guillou
*/

#define _POSIX_SOURCE

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int		main(int ac, char **av)
{
  int		pid;
  int		i;

  i = 0;
  ac = ac;
  pid = atoi(av[1]);
  while (i <= 'C')
    {
      kill(pid, SIGUSR1);
      ++i;
    }
  kill(pid, SIGUSR2);
  return (0);
}
