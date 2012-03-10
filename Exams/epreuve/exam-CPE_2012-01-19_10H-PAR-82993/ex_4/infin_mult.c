/*
** infin_mult.c for infin_mult in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 19 11:29:55 2012 exam_user
** Last update Thu Jan 19 12:59:13 2012 exam_user
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

char	*my_revstr(char *str)
{
  char	*dup;
  int	i;

  dup = malloc(my_strlen(str) * sizeof(*dup));
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      dup[my_strlen(str) - (i + 1)] = str[i];
      i--;
    }
  dup[i - (my_strlen(str) - 1)] = '\0';
  return (dup);
}

char	*my_memset(char *ptr, int len)
{
  int	i;

  i = 0;
  while (i != len)
    ptr[i++] = '\0';
  return (ptr);
}

char	*carry_out(char *res, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      if (res[i] >= 10)
	{
	  if (res[i] == 0)
	    res[i + 1] = res[i] / 10;
	  else
	    res[i + 1] = res[i + 1] + (res[i] / 10);
	  res[i] = res[i] % 10;
	}
      i++;
    }
  return (res);
}

char	*infin_mult(char *fst, char *snd)
{
  char	*src;
  char	*dst;
  char	*res;
  int	i;
  int	j;
  int	len;

  src = my_revstr(fst);
  dst = my_revstr(snd);
  res = malloc((my_strlen(fst) + my_strlen(snd) - 1) * sizeof(*res));
  res = my_memset(res, (my_strlen(fst) + my_strlen(snd) - 1));
  i = 0;
  while (is_num(src[i]))
    {
      j = 0;
      while (is_num(dst[j]))
	{
	  res[i + j] += (src[i] - '0') * (dst[j] - '0');
	  carry_out(res, (my_strlen(fst) + my_strlen(snd) - 1));
	  j++;
	}
      i++;
    }
  len = 0;
  while (len < (i + j))
    res[len++] += '0';
  if (res[len - 1] == '0')
    res[len - 1] = 0;
  res = my_revstr(res);
  if (fst[0] == '-' ^ snd[0] == '-')
    my_putchar('-');
  return (res);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    my_putstr(infin_mult(av[1], av[2]));
  my_putchar('\n');
  return (0);
}
