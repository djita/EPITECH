/*
** get_next_line.c for get_next_line in /home/guillo_e//working/prog_elem
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Nov 24 15:36:49 2011 lyoma guillou
** Last update Thu Nov 24 19:28:18 2011 lyoma guillou
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*my_strcpy(char *dst, char *src)
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
  static char	buffer[BUFF_SIZE];
  static int	len = 0;
  char		*str;
  int		rd;
  int		i;

  i = 0;
  if (READ_SIZE > BUFF_SIZE)
    return (NULL);
  if ((str = malloc(BUFF_SIZE * sizeof(*str))) == NULL)
    return (NULL);
  rd = read(fd, buffer + len, READ_SIZE - len);
  buffer[rd + len] = '\0';
  while (buffer[i] != '\n' && i < READ_SIZE)
    {
      str[i] = buffer[i];
      i++;
    }
  if (buffer[i] == '\n')
    while (buffer[i + 1] == '\n')
      str[i++] = '\n';
  str[i] = '\0';
  my_strcpy(buffer, buffer + i + 1);
  len = my_strlen(buffer);
  return (str[0] == '\0' ? NULL : str);
}
