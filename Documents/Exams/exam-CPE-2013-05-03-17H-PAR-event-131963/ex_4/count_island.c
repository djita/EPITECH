#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int is_island(char c)
{
  return (c == 'X');
}

int memlen(char **ptr)
{
  int i = 0;
  while (ptr[i])
    ++i;
  return i;
}

void has_neighbor(char **map, int i, int j, char c, int lines)
{
  if (map && map[i] && map[i][j])
    {
      map[i][j] = c;
      if (i > 0 && j > 0 && j < strlen(map[0]))
	{
	  if (map[i - 1][j] && is_island(map[i - 1][j]))
	    has_neighbor(map, i - 1, j, c, lines);
	}

      if (j > 0)
	{
	  if (map[i][j - 1] && is_island(map[i][j - 1]))
	    has_neighbor(map, i, j - 1, c, lines);
	}
      if (j < strlen(map[0]))
	{
	  if (map[i][j + 1] && is_island(map[i][j + 1]))
	    has_neighbor(map, i, j + 1, c, lines);
	}

      if (i < (lines - 1) && j > 0 && j < strlen(map[0]))
	{
	  if (map[i + 1][j] && is_island(map[i + 1][j]))
	    has_neighbor(map, i + 1, j, c, lines);
	}
    }
}

void name_island(char **map, int lines)
{
  int i = 0;
  int j = 0;
  char c = '0';

  if (map)
    for (i = 0; map[i]; ++i)
      for (j = 0; map[i][j]; ++j)
	if (is_island(map[i][j]))
	  {
	    has_neighbor(map, i, j, c, lines);
	    ++c;
	  }

}

char **getmap(char *file, size_t lines, size_t len)
{
  char **tab = NULL;
  char *buff = NULL;
  int fd = open(file, O_RDWR);
  FILE *fs = fdopen(fd, "r");
  size_t i = 0;

  tab = malloc((lines + 1) * sizeof(*tab));
  memset(tab, 0, lines + 1);
  while (-1 != getline(&buff, &len, fs))
    {
      tab[i] = strndup(buff, strlen(buff) - 1);
      ++i;
    }
  return tab;
}

void count_island(char *file)
{
  int fd = open(file, O_RDWR);
  FILE *fs = fdopen(fd, "r");
  int i = 0;
  size_t	len = 0;
  char *buff = NULL;
  char **map = NULL;

  while (-1 != getline(&buff, &len, fs))
    ++i;
  fclose(fs);
  map = getmap(file, i, len);
  if (map)
    {
      name_island(map, i);
      i = 0;
      if (map)
	while (map[i])
	  printf("%s\n", map[i++]);
    }
}

size_t main(size_t ac, char **av)
{
  if (ac == 2)
    count_island(av[1]);
  else
    write(1, "\n", 1);
}
