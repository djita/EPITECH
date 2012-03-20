/*
** count_island.c for count_island in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 10:55:28 2012 exam_user
** Last update Sat Mar 10 22:10:23 2012 lyoma guillou
*/

#include <cnt_isl.h>

char		*get_next_line(int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*dup;

  if (buffer == 0)
    buffer = malloc(4096 * sizeof(*buffer));
  read(fd, buffer + len, 4096 - len);
  len = 0;
  while (buffer[len] && buffer[len] != '\n')
    ++len;
  dup = malloc((len) * sizeof(*dup));
  strncpy(dup, buffer, len);
  strcpy(buffer, buffer + len + 1);
  return ((dup[0] == '\0') ? NULL : dup);
}

char		**recover_map(char **map, int fd)
{
  char		*str;
  int		i;

  i = 0;
  while ((str = get_next_line(fd)))
    map[i++] = str;
  map[i] = '\0';
  return (map);
}

int		_has_border(char **map, int x, int y)
{
  if (y != 0 && map[y - 1] && map[y - 1][x] == 'X')
    return (TOP);
  if (x != 0 && map[y][x - 1] == 'X')
    return (LEFT);
  if (y < my_tablen(map) && map[y + 1] && map[y + 1][x] == 'X')
    return (DOWN);
  if (x < strlen(map[0]) && map[y][x + 1] == 'X')
    return (RIGHT);
  return (0);
}

int		check_island(char **map, int x, int y, char num)
{
  int		pos;

  if (map[y][x] == 'X')
    map[y][x] = num;
  while ((pos = _has_border(map, x, y)))
    {
      if (pos & TOP)
	check_island(map, x, y - 1, num);
      if (pos & LEFT)
	check_island(map, x - 1, y, num);
      if (pos & DOWN)
	check_island(map, x, y + 1, num);
      if (pos & RIGHT)
	check_island(map, x + 1, y, num);
    }
  return (0);
}

void		count_island(char *path)
{
  int		fd;
  char		**map;
  char		num;
  int		i;
  int		j;

  map = malloc(200 * sizeof(*map));
  fd = open(path, O_RDONLY);
  recover_map(map, fd);
  i = 0;
  num = '0';
  while (map[i] && num <= '9')
    {
      j = 0;
      while (map[i][j] && num <= '9')
	{
	  if (map[i][j] == 'X' && num <= '9')
	    check_island(map, j, i, num++);
	  ++j;
	}
      ++i;
    }
  my_putmap(map);
}
