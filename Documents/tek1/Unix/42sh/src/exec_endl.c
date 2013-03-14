/*
** exec_endl.c for endl\ in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 15:27:03 2012 vincent bonmarchand
** Last update Sun May 20 21:12:40 2012 lyoma guillou
*/

#include <stdlib.h>
#include <stdio.h>

#include "lltree.h"
#include "execute.h"

int	exec_endl(t_cmd *node, int fd[2], int *stop)
{
  printf("[ENDL] -- [%s] %s [%s] \n",
	 (!node->right) ? "null" : node->right->name,
	 node->name, (!node->left) ? "null" : node->left->name);
  if (node->left != NULL)
    exec_node(node->left, fd, stop);
  if (node->right != NULL)
    return (exec_node(node->right, fd, stop));
  return (EXIT_FAILURE);
}
