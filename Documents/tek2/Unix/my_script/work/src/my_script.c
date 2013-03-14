/*
** loop.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar  2 21:59:03 2013 Lyoma Guillou
** Last update Sun Mar  3 18:34:40 2013 Lyoma Guillou
*/

#include "my_script.h"

void			ioctl_set()
{
  struct termios	t;

  tcgetattr(0, &t);
  t.c_lflag &= ~(ICANON | ISIG | ECHO);
  tcsetattr(0, TCSANOW, &t);
}

void			ioctl_restore()
{
  struct termios	term_p;

  tcgetattr(0, &term_p);
  term_p.c_lflag |= (ICANON | ISIG | ECHO);
  tcsetattr(0, TCSANOW, &term_p);
}

int			use_set(char **buff, int *len, fd_set *f_set, int m_fd)
{
  if (FD_ISSET(0, f_set))
    {
      if ((0 >= (*len = read(0, *buff, sizeof(**buff))))
	  || (0 >= write(m_fd, *buff, *len)))
	return (-1);
    }
  else if (FD_ISSET(m_fd, f_set))
    {
      if ((0 >= (*len = read(m_fd, *buff, sizeof(**buff))))
	  || (0 >= write(1, *buff, *len)))
	return (-1);
      return (1);
    }
  return (0);
}

static void		_select_f_set(int master, fd_set *f_set)
{
  FD_ZERO(f_set);
  FD_SET(0, f_set);
  FD_SET(master, f_set);
  if (select(master + 1, f_set, NULL, NULL, NULL) < 0)
    {
      fprintf(stderr, "select error\n");
      exit(EXIT_FAILURE);
    }
}

void			my_script(int master, t_opt *args)
{
  char			*buff;
  int			r_len;
  int			ret;
  fd_set		f_set;

  r_len = 0;
  if (NULL == (buff = malloc(sizeof(*buff) * 4096)))
    {
      fprintf(stderr, "malloc error\n");
      exit(EXIT_FAILURE);
    }
  while (42)
    {
      _select_f_set(master, &f_set);
      if ((ret = use_set(&buff, &r_len, &f_set, master)) == -1)
	{
	  free(buff);
	  return;
	}
      else if ((ret == 1) && (0 >= write(args->fd, buff, r_len)))
	{
	  fprintf(stderr, "write error\n");
	  exit(EXIT_FAILURE);
	}  
    }
}
