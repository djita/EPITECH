/*
** tty_util.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Mar  3 19:23:02 2013 Lyoma Guillou
** Last update Sun Mar  3 19:25:50 2013 Lyoma Guillou
*/

#include "my_script.h"

int		my_login_tty(int fd)
{
  if (-1 == dup2(fd, 0) || -1 == dup2(fd, 1) || -1 == dup2(fd, 2))
    return (-1);
  return (0);
}

int		my_openpty(int *m_fd, int *s_fd, char *name,
			   struct termios *termp, struct winsize *winp)
{
  (void) termp;
  (void) winp;
  if (0 < (*m_fd = open("/dev/ptmx", O_RDWR)))
    {
      my_grantpt(*m_fd);
      my_unlockpt(*m_fd);
      name = my_ptsname(*m_fd);
      if (0 < (*s_fd = open(name, O_RDWR)))
	return (0);
    }
  fprintf(stderr, "open error\n");
  return (-1);
}

pid_t		my_forkpty(int *m_fd, char *name,
			   struct termios *termp, struct winsize *winp)
{
  pid_t		pid;
  int		s_fd;

  if (-1 != my_openpty(m_fd, &s_fd, name, termp, winp))
    {
      if (0 > (pid = fork()))
	{
	  fprintf(stderr, "fork error\n");
	  return (-1);
	}
      else if (!pid)
	{
	  if (-1 != my_login_tty(s_fd))
	    return (0);
	}
      else
	{
	  if (!close(s_fd))
	    return (pid);
	}
    }
  fprintf(stderr, "openpty\n");
  return (-1);
}
