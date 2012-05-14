/*
** get_next_line.c for reader in /home/guillo_e//Documents/working/colles/colle2/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 20:56:01 2012 lyoma guillou
** Last update Tue Apr 24 21:39:52 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*get_next_line(int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*dup;
  int		rd;

  if (!buffer)
    if ((buffer = malloc(BUFFLEN * sizeof(*buffer))) == NULL)
      return (NULL);
  if ((rd = read(fd, buffer + len, (BUFFLEN - 1) - len)) < 0)
    return (NULL);
  len = 0;
  while (buffer[len] && buffer[len] != '\n')
    ++len;
  dup = my_strndup(buffer, len);
  my_strcpy(buffer, (buffer[len] == '\0') ? buffer + len : buffer + len + 1);
  len = my_strlen(buffer);
  if (dup[0] == '\0')
    {
      free(buffer);
      free(dup);
      dup = NULL;
    }
  return (dup);
}
