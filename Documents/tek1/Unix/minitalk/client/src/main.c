/*
** main.c for minitalk in /home/guillo_e//Documents/working/unix/minitalk/client
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Mar 15 18:15:51 2012 lyoma guillou
** Last update Fri Mar 16 13:59:43 2012 lyoma guillou
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>
#include	<client.h>

#define		CHAR_LEN	8

static void	_sendchar_sig(int pid, char c)
{
  int		i;

  i = 0;
  while (i < CHAR_LEN)
    {
      usleep(1500);
      if (c & (1 << ((CHAR_LEN) - 1 - i)))
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      ++i;
    }
}

static void	_sendstr_sig(int pid, char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      _sendchar_sig(pid, str[i]);
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 3)
    _sendstr_sig(my_getnbr(av[1]), av[2]);
  return (0);
}
