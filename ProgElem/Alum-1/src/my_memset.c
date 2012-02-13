/*
** my_memset.c for alum1 in /home/guillo_e//Documents/working/prog_elem/Alum-1
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Feb  6 11:51:59 2012 lyoma guillou
** Last update Tue Feb  7 10:53:10 2012 lyoma guillou
*/

void		*my_memset(void *ptr, int sym, int len)
{
  int		i;
  char		*str;

  i = 0;
  str = ptr;
  while (i < len)
    str[i++] = sym;
  str[i] = 0;
  return (ptr);
}
