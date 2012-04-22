/*
** my_strlen.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Apr  5 16:05:57 2012 lyoma guillou
** Last update Thu Apr  5 16:06:18 2012 lyoma guillou
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
