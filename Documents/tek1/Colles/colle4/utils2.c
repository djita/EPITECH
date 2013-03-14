/*
** utils2.c for utils2 in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 19:59:28 2012 marc deletang
** Last update Mon May  7 22:41:26 2012 lyoma guillou
*/

int		my_tablen(const char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

int		my_strncmp(char *str1, char *str2, int n)
{
  int		i;

  i = 0;
  while (str1[i] && str2[i] && i <= n)
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  return (0);
}
