/*
** main.c for bsq in /home/guillo_e//working/prog_elem/bsq
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Dec  5 13:29:54 2011 lyoma guillou
** Last update Tue Dec  6 17:12:06 2011 lyoma guillou
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "bsq.h"

int		main(int ac, char **av)
{
  int		fd;
  
  if ((fd = open(av[1], O_RDONLY)) != -1 && ac == 2)
    {
      my_puttab(sqr_chk(map_tab(fd)));
      close(fd);
    }
  return (0);
}
