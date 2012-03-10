/*
** get_next_index.c for marvin in /home/guillo_e//working/test/funcs
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Nov 27 20:55:34 2011 lyoma guillou
** Last update Sun Nov 27 21:10:53 2011 lyoma guillou
*/

int		get_type_index(char src)
{
  char		**tab;
  char		pool;
  int		len;

  tab = type_tab_init();
  pool = src - 'A';
  len =  my_strlen(tab[pool]);
  freed(tab);
  return (len + 1);
}

str + get_type_index('A')
