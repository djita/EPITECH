/*
** count_island.c for count_island in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Feb 11 11:08:02 2012 exam_user
** Last update Sat Feb 11 13:51:14 2012 exam_user
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define	BUFF_SIZE	1024
#define	UP		'u'
#define	DOWN		'd'
#define	LEFT		'l'
#define	RIGHT		'r'

static int	_is_island(char c)
{
  if (c == 'X')
    return (1);
  if (c >= '0' && c <= '9')
    return (2);
  return (0);
}

static int	_has_border(char **tab, int x, int y)
{
  if (tab[y][x] && _is_island(tab[y][x]) == 1)
    {
      if (y > 0 && tab[y - 1][x] && _is_island(tab[y - 1][x]) == 1)
	return (UP);
      if (x > 0 && tab[y][x - 1] && _is_island(tab[y][x - 1]) == 1)
	return (LEFT);
      if (tab[y + 1][x] && _is_island(tab[y + 1][x]) == 1)
	return (DOWN);
      if (tab[x][y + 1] && _is_island(tab[x][y + 1]) == 1)
	return (RIGHT);
    }
  return (0);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    i++;
  write(1, s, i);
}

char		*my_strcpy(char *dst, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*my_strncpy(char *dst, char *src, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      dst[i] = src[i];
      ++i;
    }
  dst[i] = '\0';
  return (dst);
}

char		*get_next_line(int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*dup;
  int		i;

  i = 0;
  if (buffer == 0)
    buffer = malloc(BUFF_SIZE * sizeof(*buffer));
  read(fd, buffer, BUFF_SIZE - len);
  while (buffer[i] && buffer[i] != '\n')
    i++;
  len = i;
  i = 0;
  dup = malloc(len * sizeof(*dup));
  my_strncpy(dup, buffer, len);
  my_strcpy(buffer, buffer + len + 1);
  return ((dup[0] != '\0') ? dup : NULL);
}

char		**fd_to_map(int fd)
{
  char		**tab;
  char		*ptr;
  int		i;

  i = 0;
  tab = malloc(BUFF_SIZE * sizeof(*tab));
  while (ptr = get_next_line(fd))
    tab[i++] = ptr;
  tab[i] = 0;
  return (tab);
}

char		**count_island(char **map)
{
  int		x;
  int		y;
  int		ild;
  int		bord;

  y = 0;
  ild = '0' - 1;
  x = 0;
  while (map[y][x])
    {
      ++ild;
      while (map[y] && _is_island(map[y][x]) < 1)
	{
	  if (map[y][x + 1] == '\0')
	    {
	      x = 0;
	      ++y;
	    }
	  ++x;
	}
      map[y][x] = ild;
      while (_is_island(map[y][x]) == 2)
	{
	  if ((bord = _has_border(map, x, y)) != 0)
	    {
	      if (bord == UP)
		map[--y][x] == ild;
	      if (bord == LEFT)
		map[y][--x] == ild;
	      if (bord == DOWN)
		map[++y][x] == ild;
	      if (bord == RIGHT)
		map[y][++x] == ild;
	    }
	  else
	    ++x;
	}
    }
  return (map);
}

void		show_map(char **map)
{
  int		i;
  int		j;

  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	my_putchar(map[i][j++]);
      my_putchar('\n');
      ++i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    show_map(count_island(fd_to_map(open(av[1], O_RDONLY))));
  else
    my_putchar('\n');
  return (0);
}
