/*
** main.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar  2 21:52:09 2013 Lyoma Guillou
** Last update Sun Mar  3 18:54:36 2013 Lyoma Guillou
*/

#include "my_script.h"

void			write_head_foot(enum e_stat flag, t_opt *opts)
{
  char			*buff;
  time_t		t;

  time(&t);
  if (!opts->_q)
    {
      buff = malloc(sizeof(*buff) * 200);
      if (!buff)
	{
	  fprintf(stderr, "malloc error\n");
	  exit(EXIT_FAILURE);
	}
      memset(buff, 0, 200);
      buff = (BEGIN == flag) ? strcpy(buff, "Script started on ") 
	: strcpy(buff, "Script done on ");
      strcat(buff, ctime(&t));
      if (0 >= write(opts->fd, buff, strlen(buff) + 1))
	{
	  fprintf(stderr, "write error\n");
	  exit(EXIT_FAILURE);
	}
      free(buff);
    }
}

void			term_head(t_opt *opt)
{
  char			*buff;

  buff = malloc(sizeof(*buff) * (strlen("Script started, output file is ")
				 + strlen(opt->file) + 2));
  if (!buff)
    {
      fprintf(stderr, "malloc error\n");
      exit(EXIT_FAILURE);
    }
  sprintf(buff, "Script started, output file is %s\n", opt->file);
  if (!opt->_q)
    fprintf(stdout, "%s", buff);
  else
    if (0 >= write(opt->fd, buff, strlen(buff)))
      {
	fprintf(stderr, "write error\n");
	exit(EXIT_FAILURE);
      }
  free(buff);
}

void			exit_end(t_opt *opt)
{
  if (!opt->_q)
    printf("Script done, output file is %s\n", opt->file);
  write_head_foot(END, opt);
  if (0 > close(opt->fd))
    {
      fprintf(stderr, "close error\n");
      exit(EXIT_SUCCESS);
    }
  if (!opt->_c)
    free_opt(opt);
  free(opt);
}

int			main(int ac, char **av)
{
  pid_t			pid;
  int			m_fd;
  struct termios	term_p;
  struct winsize	winp;
  t_opt			*opts;

  opts = get_opt(ac, av);
  write_head_foot(BEGIN, opts);
  term_head(opts);
  if ((pid = my_forkpty(&m_fd, NULL, &term_p, &winp)) < 0)
    {
      fprintf(stderr, "my_forkpty\n");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      (!opts->_c) ? execlp(opts->term, opts->term, NULL) : execlp(opts->cmd, opts->cmd, NULL);
      if (0 >= write(2, "execl\n", strlen("execl\n")))
	exit(EXIT_FAILURE);
    }
  ioctl_set();
  my_script(m_fd, opts);
  ioctl_restore();
  exit_end(opts);
  return (0);
}
