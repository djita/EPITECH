/*
** ord_alphlong.c for ord_alphlong in /exam//rendu/ex_6
** 
** Made by exam_user
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Oct 29 11:00:55 2011 exam_user
** Last update Sat Oct 29 15:54:21 2011 exam_user
*/

int	count_word_size(char **tab, int len)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  while (tab[i])
    {
      if (my_strlen(tab[i]) == len)
	cnt++;
      i++;
    }
  return (cnt);
}

void	show_ord_tab(char **tab, int pos, int len)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      
      i++;
    }
}

void	my_ord_tab(char **tab, char *str)
{
  int	len;
  int	i;

  len = 1;
  i = 0;
  while (len < my_strlen(str))
    {
      while (tab[i])
	{
	  if (my_strlen(tab[i]) == len)
	    show_ord_tab(tab, i, len);
	  i++;
	}
      len++;
    }
}

void	ord_alphlong(char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str);
}
