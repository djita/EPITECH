/*
** main.c for my_reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:11:09 2012 lyoma guillou
** Last update Tue Apr 24 22:50:56 2012 lyoma guillou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "reader.h"
#include "my.h"

char   		**get_xml(char *file_name)
{
  int		fd;
  char		*ret;
  char		*cut;
  char		**tab;
  int		i;

  if ((fd = open(file_name, O_RDONLY)) < 0)
    return (0);
  if ((tab = malloc(TABLEN * sizeof(*tab))) == NULL)
    return (0);
  my_memset(tab, 0, TABLEN);
  i = 0;
  while ((ret = get_next_line(fd)))
    {
      ret = epur_str(ret);
      while ((cut = cut_str(ret)))
	tab[i++] = cut;
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

int		main(int ac, char **av)
{
  t_data	**list;
  char		**tab;
  int		i;

  i = 0;
  (void) list;
  if (ac >= 2)
    {
      tab = get_xml(av[1]);
      /*      list = get_info(tab); */
      while (tab[i])
	{
	  my_putstr(tab[i++]);
	  my_putchar('\n');
	}
    }
  return (0);
}
