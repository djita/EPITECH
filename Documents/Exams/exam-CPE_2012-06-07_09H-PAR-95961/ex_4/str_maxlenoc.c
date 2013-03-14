/*
** str_maxlenoc.c for  in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jun  7 09:56:35 2012 exam_user
** Last update Thu Jun  7 11:03:28 2012 exam_user
*/

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strncmp(char *src, char *dst, int len)
{
  int		i;

  i = 0;
  while (i < len && src[i] && dst[i] && src[i] == dst[i])
    ++i;
  return (src[i] - dst[i]);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

int		is_for_arg(char *str, char **av, int len)
{
  int		i;
  int		j;

  i = 1;
  while (av[i])
    {
      j = 0;
      while (av[i][j])
	{
	  if (!my_strncmp(str, av[i] + j, len))
	    return (1);
	  ++j;
	}
      ++i;
    }
  return (0);
}

int		is_str_arg(char *str, char **av, int len)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (is_for_arg(str + i, av, len))
	return (i);
      ++i;
    }
  return (0);
}

void		str_maxlenoc(int ac, char **av)
{
  char		*str;
  int		len;
  int		ret;

  str = av[1];
  len = my_strlen(str);
  ret = 0;
  while (len > 0 && ret == 0)
    {
      ret = is_for_arg(str, av, len);
      --len;
    }
  write(1, str + ret, len);
}

int		main(int ac, char **av)
{
  if (ac > 1)
    str_maxlenoc(ac, av);
  my_putchar('\n');
  return (0);
}
