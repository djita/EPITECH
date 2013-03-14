/*
** main.c for colle in /home/guillo_e//working/colle/colle3
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 18:28:19 2011 lyoma guillou
** Last update Sun Oct 30 00:02:52 2011 lyoma guillou
*/

#include <stdlib.h>
#include "my.h"

void	print_exeption(int type, int col, int lin)
{
  my_putstr("[colle1-");
  my_putchar(type + '0');
  my_putstr("] [");
  my_put_nbr(col);
  my_putstr("] [");
  my_put_nbr(lin);
  my_putstr("] ||");
  my_putstr("[colle1-");
  my_putchar(type + '1');
  my_putstr("] [");
  my_put_nbr(col);
  my_putstr("] [");
  my_put_nbr(lin);
  my_putstr("] ||");
  my_putstr("[colle1-");
  my_putchar(type + '2');
  my_putstr("] [");
  my_put_nbr(col);
  my_putstr("] [");
  my_put_nbr(lin);
  my_putstr("]\n");
}

void	colle_print(int type, int col, int lin)
{
  if (type == 3 && (col == 1 || lin == 1))
    print_exeption(type, col, lin);
  my_putstr("[colle1-");
  my_putchar(type + '0');
  my_putstr("] [");
  my_put_nbr(col);
  my_putstr("] [");
  my_put_nbr(lin);
  my_putstr("]\n");
}

int	main()
{
  char	*buffer;
  int	len;

  buffer = NULL;
  len = 0;
  if ((len = read(0, buffer, BUFF_SIZE)) > 0)
    {
      buffer[len] = '\0';
      what_is_this_glue(buffer);
    }
  return (0);
}
