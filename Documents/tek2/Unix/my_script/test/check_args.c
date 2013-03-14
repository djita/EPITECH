/*
** check_args.c for check_args.c in /home/bigup/prog/tek2/proj/my_script/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Sat Feb 26 15:54:58 2011 dimitri doyen
** Last update Sun Mar  3 02:34:25 2013 Lyoma Guillou
*/

#include "my_script.h"

void            init_targs(t_args *args)
{
  args->flag_a = 0;
  args->flag_q = 0;
  args->flag_c = 0;
  args->flag_t = 0;
  args->flag_f = 0;
  args->filename = NULL;
  args->cmd = NULL;
  args->term = NULL;
}

void            free_targs(t_args *args)
{
  if (args->filename != NULL)
    free(args->filename);
  if (args->term != NULL)
    free(args->term);
  if (args->cmd != NULL)
    free(args->cmd);
}

void            set_arg_term(t_args *args)
{
  char          *term;

  term = 0;
  term  = getenv("SHELL");
  if (term != 0)
    {
      if (!(args->term = malloc(sizeof(*term) * strlen(term) + 1)))
        exit(write(2, "malloc\n", 8));
      strcpy(args->term, term);
    }
}

void            set_arg_filename(int ac, char **ar, t_args *args)
{
  int           i;

  for (i = 1; i < ac; i++)
    {
      if (ar[i][0] != '-')
        {
          if (ar[i - 1][1] != 'c')
            {
              if (!(args->filename = malloc(sizeof(*args->filename) * (strlen(ar[i]) + 1))))
                exit(write(2, "malloc\n", 8));
              strcpy(args->filename, ar[i]);
            }
        }
    }
}

int             find_arg(int ac, char **ar, char *param)
{
  int           i;

  for (i = 1; i < ac; i++)
    {
      if (strcmp(ar[i], param) == 0)
        return (1);
    }
  return (0);
}

void            show_usage()
{
  printf("my_script \n");
  printf("usage: script [-a] [-c] [-f] [-q] [-t] [file]\n");
  exit(1);
}

t_args          *check_args(int ac, char **ar)
{
  t_args                *args;

  if (!(args = malloc(sizeof(*args) * 1)))
    exit(write(2, "malloc\n", 8));
  init_targs(args);
  set_arg_term(args);
  set_arg_filename(ac, ar, args);
  if (find_arg(ac, ar, "-a"))
    {
      args->flag_a = 1;
      args->fdf = open(args->filename?args->filename:"typescript",
                       O_CREAT|O_RDWR|O_APPEND, 0777);
    }
  else
    args->fdf = open(args->filename?args->filename:"typescript",
                     O_CREAT|O_RDWR|O_TRUNC, 0777);
  if (find_arg(ac, ar, "-q"))
    args->flag_q = 1;
  if (find_arg(ac, ar, "-c"))
    args->flag_c = 1;
  if (find_arg(ac, ar, "-t"))
    args->flag_t = 1;
  if (find_arg(ac, ar, "-f"))
    args->flag_f = 1;
  if (find_arg(ac, ar, "-c"))
    {
      args->flag_c = 1;
      args->cmd = ar[2];
      if (ac > 3)
        args->filename = ar[3];
    }
  if (find_arg(ac, ar, "-h") || find_arg(ac, ar, "--help"))
    show_usage();
  return (args);
}
