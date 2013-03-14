/*
** utils.c for utils in /home/deleta_m//Projets/Colles/Colle_7
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 19:09:58 2012 marc deletang
** Last update Tue May 29 19:24:02 2012 marc deletang
*/

#include <stdlib.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	*xmalloc(int size)
{
  void	*ptr;

  if (!(ptr = malloc(size)))
    exit(EXIT_FAILURE);
  return (ptr);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*str_return;

  str_return = xmalloc(my_strlen(str) + 1);
  str_return = my_strcpy(str_return, str);
  return (str_return);
}
