/*
** count_island.c for count_island in /home/guillo_e//Documents/working/test/count_island
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Mar 20 15:53:07 2012 lyoma guillou
** Last update Tue Mar 20 17:30:54 2012 lyoma guillou
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  write(1, str, i);
}



char		*get_next_line(int fd)
{
  static char	*buffer = 0;
  static int	len = 0;
  char		*ret;
  int		i;

  if (buffer == 0)
    buffer = malloc(4096 * sizeof(char));
  read(fd, buffer + len, 4096 - len);
  len = 0;
  while (buffer[len] && buffer[len] != '\n')
    ++len;
  ret = malloc(len * sizeof(char));
  strncpy(ret, buffer, len);
  strcpy(buffer, buffer + len);
  return ((ret[0]) ? ret : NULL);
}

char		**map_recover(char** map, int fd)
{
  char		*str;
  int		i;

  i = 0;
  while (str = get_next_line(fd))
    {
      map[i] = str;
      ++i;
    }
  return (map);
}

void		count_island(int fd)
{
  char		**map;

  map = malloc(100);
  map_recover(map, fd);
  
}

int		main(int ac, char **av)
{
  int		fd;

  if (ac == 2)
    {
      fd = open(av[1]);
      count_island(fd);
    }
  my_putchar('\n');
  return (0);
}
