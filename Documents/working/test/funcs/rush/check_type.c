/*
** check_type.c for cpe-rush1-2016-guillo_e in /home/czegan_g/Documents/dev/school/report/svn/cpe-rush1-2016-guillo_e
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 26 20:16:55 2011 lyoma guillou
** Last update Sun Nov 27 19:03:18 2011 lyoma guillou
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>



/*
** {{{1 affectation de tous les types dans un tab
*/

char		**type_tab_init()
{
  char		**tab;

  if ((tab = malloc(14 * sizeof(*tab))) == NULL)
    return (NULL);
  tab[0] = strdup("void");
  tab[1] = strdup("float");
  tab[2] = strdup("double");
  tab[3] = strdup("int");
  tab[4] = strdup("char");
  tab[5] = strdup("short int");
  tab[6] = strdup("short");
  tab[7] = strdup("long long int");
  tab[8] = strdup("long long");
  tab[9] = strdup("long int");
  tab[10] = strdup("long double");
  tab[11] = strdup("long");
  tab[12] = strdup("struct ");
  tab[13] = NULL;
  return (tab);
}

/*
** {{{1 check si t_def existe
*/

int             struct_match(char *str)
{
  int           i;
  int		state;

  i = 2;
  state = 0;
  if (str[0] != 't' || str[1] != '_' || is_type_range(str[2]) != 1)
    return (0);
  while (str[i] >= ' ' && str[i] <= '~')
    {
      if (is_type_range(str[i]) != 1 && str[i] != ' ')
	return (0);
      if (is_type_range(str[i]) == 1)
	state = 1;
      if (is_type_range(str[i]) == 2 && state == 1)
	return (1);
      i++;
    }
  return (1);
}

/*
** {{{1 comparaison avec un type valide
*/

char		check_invar(char *str, char **tab)
{
  int		i;

  i = 0;
  while (i < 13 && strncmp(str, tab[i], strlen(tab[i])) != 0)
    i++;
  if (i == 13 && struct_match(str) != 1)
    i++;
  if (i == 14)
    return ('!');
  return ('A' + i);
}

/*
** {{{1 recup a partir de la source avec verification
*/

char		check_type(char *str)
{
  char		res;
  char		*src;
  char		**type_tab;
  int		i;

  i = 0;
  res = 0;
  src = strdup(str);
  type_tab = type_tab_init();
  res = check_invar(src, type_tab);
  if (res != '!' && res != 'N')
    src = src + strlen(type_tab[res - 'A']) + 1;
  else
    return (res);
  while (src[0] != '\0' && src[0] != '(' && src[0] != ',' && src[0] != ';') 
    {
      if (check_type(src) != '!')
	return ('!');
      src = src + 1;
    }
  i = 0;
  while (type_tab[i])
    free(type_tab[i++]);
  free(type_tab);
  return (res);
}

int		main(int ac, char **av)
{
  char		res;

  res = check_type(av[1]);
  printf("%c\n", res);
}
