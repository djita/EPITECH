/*
** my_getenv.c for src in /home/falck_m/Work/42sh/src
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Sat May 12 14:40:27 2012 mickael falck
** Last update Sat May 12 14:40:31 2012 mickael falck
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*my_getenv(char *str)
{
  int		i;

  i = 0;
  while (g_my_env[i])
    {
      if (!strncmp(str, g_my_env[i], strlen(str)) 
	  && g_my_env[i][strlen(str)] == '=')
	return (g_my_env[i] + strlen(str) + 1);
      ++i;
    }
  return (NULL);
}
