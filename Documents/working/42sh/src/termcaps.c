/*
** termcaps.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Fri May 11 16:24:41 2012 mickael falck
** Last update Sun May 20 12:18:19 2012 mickael falck
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <curses.h>
#include <fcntl.h>
#include <term.h>
#include "termcaps.h"
#include "env.h"
#include "errors.h"

int		get_tty(int new_fd)
{
  static int	fd = 0;

  if (new_fd != -1)
    fd = new_fd;
  return (fd);
}

int	tputc(int c)
{
  return (write(get_tty(-1), &c, 1));
}

void	tputstr(char *str)
{
  while (str && *str)
    tputc((int)*(str++));
}

int	termcommand(char *cmd)
{
  if (cmd == NULL
      || get_tty(-1) == 0
      || (!isatty(0))
      || (cmd = tgetstr(cmd, NULL)) == NULL
      || (cmd = tparm(cmd)) == NULL
      || (tputs(cmd, 1, tputc)) == -1)
    return (-1);
  else
    return (0);
}

void		init_termcap(void)
{
  t_termios	tios;
  char		*termenv;
  int		a;

  if ((get_tty(open("/dev/tty", O_RDWR)) == 0) || !isatty(0)
      || ((termenv = my_getenv("TERM")) == NULL)
      || ((a = tgetent(NULL, termenv)) <= 0)
      || ((tcgetattr(get_tty(-1), &tios)) == -1))
    {
      my_err("Init", ERR_TERMCAPS, CONTINUE);
      get_tty(0);
    }
  else
    {
      tios.c_lflag &= ~(ECHO | ICANON);
      tios.c_cc[VMIN] = 1;
      tios.c_cc[VTIME] = 50;
      if ((tcsetattr(get_tty(-1), TCSANOW, &tios)) == -1
	  || termcommand("ks") == -1)
	{
	  my_err("Init", ERR_TERMCAPS, CONTINUE);
	  get_tty(0);
	}
    }
}
