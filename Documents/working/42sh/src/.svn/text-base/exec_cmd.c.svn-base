/*
** exec_cmd.c for src in /mnt/fedora_std/home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Sun May 20 18:46:24 2012 mickael falck
** Last update Sun May 20 22:09:15 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "str_to_wordtab.h"
#include "my_strndup.h"
#include "execute.h"
#include "errors.h"
#include "lltree.h"
#include "built.h"

int		exec_cmd(t_cmd *node, int fd[2], int *stop)
{
  char		**args;
  int		ret;

  (void)stop;
  printf("[CMD] -- [%s]\n", node->name);
  args = str_to_wordtab(node->name);
  ret = built_in(args, fd);
  if (ret == BLT_NOTFOUND)
    my_err(args[0], ERR_CMDNFOUND, CONTINUE);
  free_tab(args);
  return ((ret != BLT_NOTFOUND) ? ret : EXIT_FAILURE);
}
