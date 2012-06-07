/*
** exec_logop.c for 42sh in /home/bonmar_v//Projets/SVN/42sh
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 14:36:37 2012 vincent bonmarchand
** Last update Sun May 20 19:26:23 2012 vincent bonmarchand
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lltree.h"
#include "execute.h"

int	exec_logop(t_cmd *node, int fd[2], int *stop)
{
  int	ret;

  printf("[Logical operation] -- [%s] %s [%s] \n", node->right->name,
	 node->name, node->left->name);
  ret = 0;
  if (node->left != NULL)
    ret = exec_node(node->left, fd, stop);
  if ((!strcmp(node->name, "||")
       || (!strcmp(node->name, "&&") && ret == EXIT_SUCCESS))
      && node->right != NULL)
    ret = exec_node(node->right, fd, stop);
  return (ret);
}
