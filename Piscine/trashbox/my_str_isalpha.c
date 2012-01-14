/*
** my_str_isalpha.c for my_str_isalpha in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 15:35:17 2011 lyoma guillou
** Last update Mon Oct 10 18:49:24 2011 lyoma guillou
*/

int     is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i])
	{
	  if (is_alpha(str[i]) == 0)
	    return (0);
	  i++;
	}
    }
  return (1);
}
