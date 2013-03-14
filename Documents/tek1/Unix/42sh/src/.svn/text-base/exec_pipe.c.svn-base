/*
** exec_pipe.c for 42sh in /home/bonmar_v//Projets/SVN/42sh
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 14:35:52 2012 vincent bonmarchand
** Last update Sun May 20 19:24:33 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "lltree.h"
#include "execute.h"

int	exec_pipe(t_cmd *node, int fd[2], int *stop)
{
  int	pipe_fd[2];
  int	r_fd[2];
  int	l_fd[2];

  printf("[Pipe] -- [%s] %s [%s] \n", node->right->name,
	 node->name, node->left->name);
  pipe(pipe_fd);
  r_fd[0] = fd[0];
  l_fd[1] = fd[1];
  r_fd[1] = pipe_fd[1];
  l_fd[0] = pipe_fd[0];
  if (node->left != NULL)
    exec_node(node->left, l_fd, stop);
  if (node->right != NULL)
    exec_node(node->right, r_fd, stop);
  return (EXIT_SUCCESS);
}
