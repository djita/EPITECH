/*
** my_signal.c for signal in /home/guillo_e//Documents/working/unix/minitalk/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 18:54:08 2012 lyoma guillou
** Last update Thu Mar  8 15:00:13 2012 lyoma guillou
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char		c = 0;

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  write(1, str, i);
}

void		signal_handler(int signo)
{
  if (signo)
    my_putchar(c);
}

void		signal_start(int signo)
{
  if (signo)
    {
      usleep(50);
      ++c;
    }
}

int		main()
{
  int		i;
  int		pid;

  i = 0;
  pid = getpid();
  printf("=%d=\n", pid);
  while (i >= 0)
    {
      signal(SIGUSR2, signal_handler);
      signal(SIGUSR1, signal_start);
    }
  return (0);
}
