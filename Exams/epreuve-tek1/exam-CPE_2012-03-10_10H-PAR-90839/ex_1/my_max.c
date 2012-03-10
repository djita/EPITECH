/*
** my_max.c for my_max in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Mar 10 10:33:24 2012 exam_user
** Last update Sat Mar 10 10:39:58 2012 exam_user
*/

int		my_max(int itab[], int len)
{
  int		i;
  int		x;

  i = 0;
  x = 0;
  while (i < len)
    {
      if (x < itab[i])
	{
	  x = itab[i];
	  i = 0;
	}
      ++i;
    }
  return (x);
}
