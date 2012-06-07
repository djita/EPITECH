/*
** exec_redir.c for redir in /home/bonmar_v//Projets/SVN/42sh
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 14:37:51 2012 vincent bonmarchand
** Last update Sun May 20 21:25:53 2012 lyoma guillou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lltree.h"
#include "execute.h"

#define GETRD(x) strlen(x) == 1 ? O_TRUNC : O_APPEND

static int	_is_char(char c)
{
  return ((c > ' ' && c <= '~'));
}

static char	*_format_str(char *str)
{
  int		i;

  i = 0;
  while (_is_char(str[i]))
    ++i;
  str[i] = '\0';
  return (str);
}

int	exec_redir(t_cmd *node, int fd[2], int *stop)
{
  int	t_fd[2];

  printf("[Redirection] -- [%s] %s [%s] \n",
	 (!node->right) ? "null" : node->right->name,
	 node->name, (!node->left) ? "null" : node->left->name);
  node->left->name = _format_str(node->left->name);
  t_fd[0] = fd[0];
  t_fd[1] = fd[1];
  if (node->name[0] == '>')
    {
      t_fd[1] = open(node->left->name, O_CREAT | (GETRD(node->left->name)));
      if (node->right != NULL)
	exec_node(node->right, t_fd, stop);
    }
  else
    {
      t_fd[0] = open(node->left->name, O_RDONLY);
      if (node->right != NULL)
	exec_node(node->right, t_fd, stop);
    }
  return (EXIT_SUCCESS);
}
