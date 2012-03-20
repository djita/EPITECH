/*
** main.c for minitalk server in /home/guillo_e//Documents/working/unix/minitalk/server
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Mar  5 17:40:27 2012 lyoma guillou
** Last update Fri Mar 16 13:55:16 2012 lyoma guillou
*/

#include	<signal.h>
#include	<unistd.h>
#include	<serv.h>

char		g_char = 1;

static int	_is_printchar(char c)
{
  if ((c >= ' ' && c <= '~') || (c >= '\b' && c <= '\r'))
    return (1);
  return (0);
}

static void	_signal_catch(int signo)
{
  static int	sig_cnt = 0;

  if (sig_cnt >= 8)
    {
      sig_cnt = 0;
      g_char = 1;
    }
  g_char <<= 1;
  g_char |= (signo == SIGUSR1) ? 1 : 0;
  ++sig_cnt;
}

static void	_getchar_sig()
{
  int		cnt;

  cnt = 0;
  signal(SIGUSR1, _signal_catch);
  signal(SIGUSR2, _signal_catch);
  while (cnt < 8)
    {
      if (pause() < 0)
	++cnt;
    }
  return;
}

int		main()
{
  unsigned int	pid;

  pid = getpid();
  my_putstr("=SERVER PID: ");
  my_putnbr(pid);
  my_putstr("=\n");
  while (g_char != 0)
    {
      _getchar_sig();
      if (_is_printchar(g_char))
	my_putchar(g_char);
    }
  return (0);
}
