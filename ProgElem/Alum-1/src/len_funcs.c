/*
** my_strlen.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 14:11:09 2012 lyoma guillou
** Last update Tue Feb  7 10:31:23 2012 lyoma guillou
*/

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i++]);
  return (i);
}

int		my_tablen(char **t)
{
  int		i;

  i = 0;
  while (t[i++]);
  return (i);
}

int		my_intlen(int nb)
{
  int		i;

  i = 0;
  while (nb >= 10)
    {
      nb = nb / 10;
      ++i;
    }
  return (i);
}
