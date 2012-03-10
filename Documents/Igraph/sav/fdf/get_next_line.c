/*
** get_next_line.c for get_next_line in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 15:36:49 2011 lyoma guillou
** Last update Fri Dec  9 14:22:45 2011 lyoma guillou
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "fdf.h"

char            *my_strset(char *str, int size)
{
  int           i;

  i = 0;
  while (i < size)
    {
      str[i] = '\0';
      i = i + 1;
    }
  return (str);
}

int		my_bufflen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char		*my_buffreset(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i++;
    }
  dst[i] = '\0';
  return (dst);
}

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
  buffer[rd + len] = '\0';
  str = my_strset(str, BUFF_SIZE);
  while (buffer[++i] != '\n' && i < READ_SIZE)
    str[i] = buffer[i];
  if (buffer[i] == '\n')
    while (buffer[i + 1] == '\n')
      str[i++] = '\n';
  my_buffreset(buffer, buffer + i + 1);
  len = my_bufflen(buffer);
  return ((str[0] == '\0') ? NULL : str);
}
