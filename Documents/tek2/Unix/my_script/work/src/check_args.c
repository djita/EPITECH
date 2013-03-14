/*
** check_args.c for my_script in /home/guillo_e/Documents/working/tek2/unix/my_script/work
** 
** Made by Lyoma Guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar  2 21:58:35 2013 Lyoma Guillou
** Last update Sun Mar  3 18:26:12 2013 Lyoma Guillou
*/

#include "my_script.h"

void		free_opt(t_opt *set)
{
  if (set->file)
    free(set->file);
  if (set->term)
    free(set->term);
  if (set->cmd)
    free(set->cmd);
}

static t_opt	*_init_opt()
{
  t_opt		*set;

  set = malloc(sizeof(*set));
  if (!set)
    {
      fprintf(stderr, "malloc error\n");
      exit(EXIT_FAILURE);
    }
  set->_a = false;
  set->_q = false;
  set->_c = false;
  set->_t = false;
  set->_f = false;
  set->file = strdup("typescript");
  if (!set->file)
    {
      fprintf(stderr, "dup fail\n");
      exit(EXIT_FAILURE);
    }
  set->cmd = NULL;
  set->term = NULL;
  set->fd = 0;
  return (set);
}

static void	_set_file(int ac, char **av, t_opt *opt)
{
  int		i;

  i = 1;
  while (i < ac)
    {
      if ((av[i][0] != '-') && (av[i - 1][1] != 'c'))
	{
	  opt->file = malloc(sizeof(*opt->file) * (strlen(av[i]) + 1));
	  if (!opt->file)
	    {
	      fprintf(stderr, "malloc error\n");
	      exit(EXIT_FAILURE);
	    }
	  strcpy(opt->file, av[i]);
	}
      ++i;
    }
}

static bool	_find_opt(int ac, char **av, char *param)
{
  int		i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], param) == 0)
	return (true);
      ++i;
    }
  return (false);
}

t_opt          *get_opt(int ac, char **av)
{
  t_opt                *opt;

  opt = _init_opt();
  opt->term = getenv("SHELL") ? strdup(getenv("SHELL")) : NULL;
  _set_file(ac, av, opt);
  if (_find_opt(ac, av, "-h") || _find_opt(ac, av, "--help"))
    {
      fprintf(stdout, "my_script\nusage: script [-a] [-c] [-f] [-q] [-t] [file]\n");
      exit(EXIT_SUCCESS);
    }
  opt->_a = _find_opt(ac, av, "-a");
  opt->_q = _find_opt(ac, av, "-q");
  opt->_c = _find_opt(ac, av, "-c");
  opt->_t = _find_opt(ac, av, "-t");
  opt->_f = _find_opt(ac, av, "-f");
  opt->cmd = (opt->_c) ? strdup(av[2]) : opt->cmd;
  opt->file = (opt->_c && ac > 3) ? strdup(av[3]) : opt->file;
  opt->fd = open(opt->file, (!opt->_a) ? O_CREAT | O_RDWR | O_TRUNC 
		 : O_CREAT | O_RDWR | O_APPEND, 0644);
  if (0 > opt->fd)
    {
      fprintf(stderr, "couldn't open file\n");
      exit(EXIT_FAILURE);
    }
  return (opt);
}
