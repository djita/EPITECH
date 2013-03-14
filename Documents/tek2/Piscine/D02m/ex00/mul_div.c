/*
** mul_div.c for mul_div in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 09:05:27 2013 lyoma guillou
** Last update Thu Jan 10 09:14:57 2013 lyoma guillou
*/

void		add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void		add_mul_2param(int *first, int *second)
{
  add_mul_4param(*first, *second, first, second);
}
