/*
** utils3.c for utils3 in /u/all/guillo_e/public/deleta_m
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Tue May 29 20:25:39 2012 marc deletang
** Last update Tue May 29 22:14:25 2012 lyoma guillou
*/

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] && str2[i] && i < n && str1[i] == str2[i])
    i++;
  return (str1[i] - str2[i]);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
