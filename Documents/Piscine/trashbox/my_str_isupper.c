/*
** my_str_isupper.c for my_str_isupper in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon Oct 10 18:59:16 2011 lyoma guillou
** Last update Mon Oct 10 19:20:12 2011 lyoma guillou
*/

int	is_up_alpha(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  if (str[0] != '\0')
    {
      while (str[i])
	{
	  if (is_up_alpha(str[i]))
	    return (0);
	  i++;
	}
    }
  return (1);
}
