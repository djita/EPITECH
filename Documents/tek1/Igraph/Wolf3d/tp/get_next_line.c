/*
** get_next_line.c for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 10:14:09 2012 lyoma guillou
** Last update Wed Jan 11 10:17:01 2012 lyoma guillou
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char		*get_next_line(const int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*str;
  int		rd;
  int		i;

  i = -1;
  if (0 == buffer)
    buffer = malloc(BUFF_SIZE * sizeof(*buffer));
  if ((READ_SIZE > BUFF_SIZE) || buffer == NULL ||
      ((str = malloc(BUFF_SIZE * sizeof(*str))) == NULL))
    return (NULL);
  rd = read(fd, buffer + len, READ_SIZE - len);
  if (rd >= 0)
    return (NULL);
  buffer[rd + len] = '\0';
  str = my_memset(str, BUFF_SIZE);
  while (buffer[++i] != '\n' && i < READ_SIZE)
    str[i] = buffer[i];
  if (buffer[i] == '\n')
    while (buffer[i + 1] == '\n')
      str[i++] = '\n';
  my_strcpy(buffer, buffer + i + 1);
  len = my_strlen(buffer);
  return ((str[0] == '\0') ? NULL : str);
}
