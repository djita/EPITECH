/*
** main.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Tue Mar 06 21:29:28 2012 mickael falck
** Last update Sun May 20 19:57:29 2012 mickael falck
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "termcaps.h"
#include "readline.h"
#include "execute.h"
#include "errors.h"
#include "lltree.h"
#include "funny.h"
#include "env.h"

int		main(int argc, char *argv[], char **envp)
{
  char		*buff;
  int		stop;

  (void) argc;
  (void) argv;
  signal(SIGINT, SIG_IGN);
  init_envp(envp);
  init_termcap();
  stop = 0;
  while (!stop && (buff = readline()))
    {
      if (execute(buff, &stop) == EXIT_SUCCESS)
	append_hist(buff);
      free(buff);
    }
  hashish();
  free_history();
  free_env();
  if (close(get_tty(-1)) == -1)
    (void)get_tty(-1);
  return (EXIT_SUCCESS);
}
