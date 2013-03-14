/*
** magicsquare.c for magicsqaure in /exam//rendu/ex_3
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Feb 22 19:07:17 2012 exam_user
** Last update Wed Feb 22 20:54:10 2012 exam_user
*/

#include <stdlib.h>

char		*rand_num(char *sqr);

static int      is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

static int	is_15(char a, char b, char c)
{
  if ((a - '0') + (b - '0') + (c - '0') == 15)
    return (1);
  return (0);
}

static int	_zero_check(char *sqr)
{
  if (!is_15(sqr[0], sqr[1], sqr[2]) || 
      !is_15(sqr[0], sqr[3], sqr[6]) ||
      !is_15(sqr[0], sqr[4], sqr[8]))
    return (0);
  return (1);
}

static int	_one_check(char *sqr)
{
  if (!is_15(sqr[0], sqr[1], sqr[2]) ||
      !is_15(sqr[1], sqr[4], sqr[7]))
    return (0);
  return (1);
}

static int	_two_check(char *sqr)
{
  if (!is_15(sqr[0], sqr[1], sqr[2]) || 
      !is_15(sqr[2], sqr[5], sqr[8]) ||
      !is_15(sqr[2], sqr[4], sqr[6]))
    return (0);
  return (1);
}

static int	_three_check(char *sqr)
{
 if (!is_15(sqr[3], sqr[4], sqr[5]) || 
     !is_15(sqr[0], sqr[3], sqr[6]))
   return (0);
 return (1);
}

static int	_four_check(char *sqr)
{
  if (!is_15(sqr[3], sqr[4], sqr[5]) || 
      !is_15(sqr[1], sqr[4], sqr[7]) || 
      !is_15(sqr[0], sqr[4], sqr[8]) || 
      !is_15(sqr[2], sqr[4], sqr[6]))
    return (0);
  return (1);
}

static int	_five_check(char *sqr)
{
  if (!is_15(sqr[3], sqr[4], sqr[5]) ||
      !is_15(sqr[2], sqr[5], sqr[8]))
    return (0);
  return (1);
}

static int	_six_check(char *sqr)
{
  if (!is_15(sqr[6], sqr[7], sqr[8]) ||
      !is_15(sqr[0], sqr[3], sqr[6]) ||
      !is_15(sqr[2], sqr[4], sqr[6]))
    return (0);
  return (1);
}

static int	_seven_check(char *sqr)
{
  if (!is_15(sqr[6], sqr[7], sqr[8]) || 
      !is_15(sqr[1], sqr[4], sqr[7]))
    return (0);
  return (1);
}

static int	_eight_check(char *sqr)
{
  if (!is_15(sqr[6], sqr[7], sqr[8]) || 
      !is_15(sqr[2], sqr[5], sqr[8]) ||
      !is_15(sqr[0], sqr[4], sqr[8]))
    return (0);
  return (1);
}

static int	mass_check(char *sqr)
{
  if (!is_15(sqr[0], sqr[1], sqr[2]) || 
      !is_15(sqr[3], sqr[4], sqr[5]) || 
      !is_15(sqr[6], sqr[7], sqr[8]) || 
      !is_15(sqr[0], sqr[3], sqr[6]) || 
      !is_15(sqr[1], sqr[4], sqr[7]) || 
      !is_15(sqr[2], sqr[5], sqr[8]) || 
      !is_15(sqr[0], sqr[4], sqr[8]) || 
      !is_15(sqr[2], sqr[4], sqr[6]))
    return (0);
  return (1);
}

static int	check_pos(char *sqr, int pos)
{
  if ((rand_num(sqr)) == NULL)
    return (0);
  if (pos == 0)
    return (_zero_check(sqr));
  if (pos == 1)
    return (_one_check(sqr));
  if (pos == 2)
    return (_two_check(sqr));
  if (pos == 3)
    return (_three_check(sqr));
  if (pos == 4)
    return (_four_check(sqr));
  if (pos == 5)
    return (_five_check(sqr));
  if (pos == 6)
    return (_six_check(sqr));
  if (pos == 7)
    return (_seven_check(sqr));
  if (pos == 8)
    return (_eight_check(sqr));
}

char		*rand_num(char *sqr)
{
  int		i;

  i = 0;
  while (sqr[i])
    {
      if (sqr[i] == '?')
	{
	  sqr[i] = '0';
	  while (!check_pos(sqr, i))
	    {
	      sqr[i] += 1;
	      if (sqr[i] > '9')
		return (NULL);
	    }
	}
      ++i;
    }
  return (sqr);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int             my_strlen(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}

void            my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*fill_sqr(char *sqr, char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (is_num(str[i]) || str[i] == '?')
	sqr[j++] = str[i];
      ++i;
    }
  sqr[j] = '\0';
  return (sqr);
}

void		show_sqr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i++]);
      my_putchar(' ');
    }
}

int		magicsquare(char *str)
{
  char		*sqr;

  if (my_strlen(str) != 17)
    return (0);
  sqr = malloc(10 * sizeof(*sqr));
  sqr = fill_sqr(sqr, str);
  sqr = rand_num(sqr);
  if (sqr != NULL && mass_check(sqr))
    {
      show_sqr(sqr);
      return (1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  int		i;

  i = 0;
  if (ac == 2)
    i = magicsquare(av[1]);
  my_putstr((i == 1) ? "OK" : "KO");
  my_putchar('\n');
  return (0);
}
