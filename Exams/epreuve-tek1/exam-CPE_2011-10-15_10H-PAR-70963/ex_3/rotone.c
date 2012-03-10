/*
** rotone.c for rotone in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 15 10:09:21 2011 exam_user
** Last update Sat Oct 15 10:53:45 2011 exam_user
*/

#include <stdlib.h>

int	is_alphanum(char c)
{
  if ((c >= 'a' && c < 'z') || (c >= 'A' && c < 'Z'))
    return (1);
  if (c == 'z' || c == 'Z')
    return (2);
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}

int	main(int argc, char **argv)
{
  int	j;

  j = 0;
  if (argc == 2)
    {
      while (argv[1][j])
	{
	  if (is_alphanum(argv[1][j]) > 0)
	    {
	      if (is_alphanum(argv[1][j]) == 2)
		my_putchar(argv[1][j] - ('z' - 'a'));
	      if (is_alphanum(argv[1][j]) == 1)
		my_putchar(argv[1][j] + 1);
	    }
	  else
	    my_putchar(argv[1][j]);
	  j++;
	}
    }
  my_putchar('\n');
  return (0);
}
