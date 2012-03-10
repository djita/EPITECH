/*
** my_putstr.c for infin_add in /exam//rendu/ex_4
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 12 10:50:50 2011 exam_user
** Last update Sat Nov 12 10:51:14 2011 exam_user
*/

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  write(1, str, i);
}
