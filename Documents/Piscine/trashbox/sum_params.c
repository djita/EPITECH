/*
** sum_params.c for sum_params in /home/guillo_e//Documents/Piscine
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Oct 13 13:17:23 2011 lyoma guillou
** Last update Thu Oct 13 16:26:58 2011 lyoma guillou
*/

#include <stdlib.h>

void	*xmalloc(int size)
{
  char	*ptr;

  ptr = malloc((size + 1) * sizeof(char));
  if (ptr == NULL)
    return (NULL);
}

int	chain_len(char **argv)
{
  int	i;
  int	j;
  int	len;

  i = 0;
  len = 0;
  while (argv[i])
    {
      j = 0;
      while (argv[i][j])
	j++;
      len = len + j;
      i++;
    }
  return (len);
}

char	*sum_params(int argc, char **argv)
{
  int	i;
  int	j;
  int	k;
  int	len;
  char	*str;

  i = 0;
  k = 0;
  len = chain_len(argv);
  str = xmalloc(len);
  while (argv[i])
    {
      j = 0;
      while (argv[i][j])
	{
	  str[k] = argv[i][j];
	  j++;
	  k++;
	}
      str[k] = '\n';
      k++;
      i++;
    }
  str[k - 1] = '\0';
  return (str);
}

int	main(int ac, char **av)
{
  my_putstr(sum_params(ac, av));
  return;
}
