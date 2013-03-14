/*
** my_strstr.c for my_strstr in /home/guillo_e//afs/rendu/piscine/Jour_06/ex_04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 10:46:40 2011 lyoma guillou
** Last update Mon Oct 10 20:33:19 2011 lyoma guillou
*/

char    *my_strstr(char *str, char *to_find)
{
  int   i;
  int   j;

  i = 0;
  while (str[i])
    {
      j = 0;
      while (str[i + j] == to_find[j])
	{
	  j++;
	  if (to_find[j] == '\0')
	    return (str + i);
	}
      i++;
    }
  return (0);
}
