/*
** my_strlen.c for reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:48:39 2012 lyoma guillou
** Last update Tue Apr 24 20:14:46 2012 lyoma guillou
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    ++i;
  return (i);
}
