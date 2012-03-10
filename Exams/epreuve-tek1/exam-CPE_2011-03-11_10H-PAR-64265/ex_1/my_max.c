/*
** my_max.c for my_max in /exam//rendu/ex_1
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 11 10:35:05 2011 exam_user
** Last update Fri Mar 11 10:43:33 2011 exam_user
*/

int	my_max(int *itab, int len)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (i < len)
    {
      if (itab[i] > itab[x])
	{
	  x = i;
	  i = 0;
	}
      i++;
    }
  return (itab[x]);
}
