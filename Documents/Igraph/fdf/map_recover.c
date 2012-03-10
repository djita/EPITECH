/*
** map_recover.c for fdf in /home/guillo_e//working/igraph/fdf
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec  9 14:05:14 2011 lyoma guillou
** Last update Sun Dec 11 19:46:04 2011 lyoma guillou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"

t_dot		*init(int x, int y, int z)
{
  t_dot		*dot;

  if ((dot = malloc(sizeof(*dot))) == NULL)
    return (NULL);
  dot->x = x;
  dot->y = y;
  dot->z = z;
  dot->next = NULL;
  return (dot);
}

t_dot		*app_to_list(t_dot *first, t_dot *cur)
{
  t_dot		*tmp;

  if (NULL == first)
    return (cur);
  tmp = first;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = cur;
  return (first);
}

t_dot		*map_recover(t_dot *list, int *line, int size, int row)
{
  t_dot		*elem;
  int		i;

  i = 0;
  while (i < size)
    {
      elem = init((i * UNTX), (row * UNTY), line[i] * DENS);
      list = app_to_list(list, elem);
      i = i + 1;
    }
  return (list);
}

t_dot		*map_elem(char *path)
{
  t_dot		*list;
  char		**tab;
  char		*str;
  int		*line;
  int		fd;
  int		i;
  int		len;

  i = 0;
  list = NULL;
  fd = open(path, O_RDONLY);
  while ((str = get_next_line(fd)))
    {
      tab = my_str_to_wordtab(str);
      len = get_tablen(tab);
      line = get_line_int(tab);
      list = map_recover(list, line, len, i);
      free(str);
      i = i + 1;
    }
  return (list);
}
