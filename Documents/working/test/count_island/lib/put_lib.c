/*
** put_lib.c for count_island in /home/guillo_e//Documents/working/test/count_island
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 21:52:38 2012 lyoma guillou
** Last update Sat Mar 10 21:53:28 2012 lyoma guillou
*/

#include <cnt_isl.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  write(1, str, strlen(str));
}

void		my_putmap(char **map)
{
  int		i;

  i = 0;
  while (map[i])
    {
      my_putstr(map[i++]);
      my_putchar('\n');
    }
}
