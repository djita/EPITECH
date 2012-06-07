/*
** built_pwd.c for built_pwd in /home/bonmar_v//Projets/SVN/42sh/src
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 21:35:51 2012 vincent bonmarchand
** Last update Sun May 20 21:42:26 2012 vincent bonmarchand
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_pwd(char **arg, int fd[2])
{
  char	*path;

  (void)arg;
  (void)fd;
  path = getcwd(NULL, 0);
  if (path == NULL)
    return (EXIT_FAILURE);
  printf("%s\n", path);
  return (EXIT_SUCCESS);
}
