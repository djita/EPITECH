/*
** rev_wstr.c for rev_wstr in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Feb 22 17:33:42 2012 exam_user
** Last update Wed Feb 22 18:27:37 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		is_alphanum(char c)
{
  if (c <= ' ' || c > '~')
    return (0);
  return (1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void		rev_wstr(char *str)
{
  int		i;
  int		j;
  int		k;
  int		word;

  i = my_strlen(str);
  j = 0;
  k = i;
  word = 0;
  while (i >= 0)
    {
      if ((!is_alphanum(str[i]) || i == 0) && word == 1)
	{
	  j = (i == 0) ? i : i + 1;
	  while (j < k)
	    {
	      if (str[j] != ' ')
		my_putchar(str[j]);
	      j++;
	    }
	  k = i;
	  if (i != 0)
	    my_putchar(' ');
	  word = 0;
	}
      if (is_alphanum(str[i]))
	word = 1;
      --i;
    }
}

int		main(int ac, char **av)
{
  if (ac == 2)
    rev_wstr(av[1]);
  my_putchar('\n');
  return (0);
}
