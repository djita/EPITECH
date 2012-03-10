/*
** my_signal.c for signal in /home/guillo_e//Documents/working/unix/minitalk/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 18:54:08 2012 lyoma guillou
** Last update Sat Mar 10 16:00:37 2012 lyoma guillou
*/

#define _BSD_SOURCE

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char		c = 0;
int		i = 0;

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

void		signal_bit0(int signo)
{
  signo = signo;
  c <<= 1;
  c |= 0;
  ++i;
}

void		signal_bit1(int signo)
{
  signo = signo;
  c <<= 1;
  c |= 1;
  ++i;
}

int		main()
{
  int		pid;

  pid = getpid();
  printf("=%d=\n", pid);
  while (i < 8)
    {
      signal(SIGUSR1, signal_bit1);
      signal(SIGUSR2, signal_bit0);
    }
  printf("char: %c, value: %d, nb_signal: %d\n", c, c, i);
  return (0);
}
