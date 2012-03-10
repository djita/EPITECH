/*
** main.c for infin_add in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 10:51:41 2011 exam_user
** Last update Sat Nov 12 12:53:37 2011 exam_user
*/

#include <stdlib.h>
#include <stdio.h>

char	char_add(char un1, char un2)
{
  char	res;

  if (!un1 && un2 > 0)
    res = un2 - '0';
  else
    res = -un2 - '0';
  if (!un2 && un1 > 0)
    res = un1 - '0';
  else
    res = -un1 - '0';
  if (un1 < 0 && un2 < 0)
    res = (-un1 - '0') + (-un2 - '0');
  else
    res = (un1 - '0') + (un2 - '0');
  return (res);
}

char	carry_out(char num)
{
  if (num >= 10)
    return (1);
  if (num < 0)
    return (-1);
  else
    return (0);
}

char	*res_len(char *s1, char *s2)
{
  char	*res;

  if (my_strlen(s1) >= my_strlen(s2))
    res = malloc((my_strlen(s1) + 1) * sizeof(*res));
  else
    res = malloc((my_strlen(s2) + 1) * sizeof(*res));
  if (NULL == res)
    return (NULL);
  return (res);
}

char	*my_add(char *s1, char *s2)
{
  int	carry;
  int	i;
  char	*res;

  carry = 0;
  i = 0;
  res = res_len(s1, s2) + 1;
  while (s1[i] || s2[i])
    {
      res[i] = carry + char_add(s1[i], s2[i]);
      carry = carry_out(res[i]);
      if (carry > 0)
	res[i] = res[i] - 10;
      if (carry < 0)
	res[i] = res[i] + 10;
      res[i] = res[i] + '0';
      i++;
    }
  if (carry != 0)
    {
      res[i] = carry + '0';
      i = i + 1;
    }
  res[i] = '\0';
  return (res);
}

int	main(int ac, char *av[])
{
  char	*ex1;
  char	*ex2;
  char	*res;

  if (av[2])
    {
      ex1 = my_revstr(av[1]);
      ex2 = my_revstr(av[2]);
      res = my_add(ex1, ex2);
      my_putstr(my_revstr(res));
    }
  my_putchar('\n');
  return (0);
}
