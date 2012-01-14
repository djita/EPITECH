/*
** list_func.c for test in /home/guillo_e//working/test/funcs
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sun Nov 27 02:34:30 2011 lyoma guillou
** Last update Sun Nov 27 03:10:37 2011 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_exp
{
  char		*name;
  struct s_exp	*next;
}		t_exp;

t_exp		*init_elem(char *name)
{
  t_exp		*link;

  if ((link = malloc(sizeof(*link))) == NULL)
    return (0);
  link->name = name;
  link->next = NULL;
  return (link);
}

int		app_name_list(t_exp **exp, char *name)
{
  t_exp		*elem;
  t_exp		*cur;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (0);
  cur = *exp;
  while (cur->next != NULL)
    cur = cur->next;
  elem->name = name;
  cur->next = elem;
  elem->next = NULL;
  return (1);
}

void		show_list(t_exp *list)
{
  t_exp		*cur;
  
  cur = list;
  while (cur != NULL)
    {
      printf("%s\n", cur->name);
      cur = cur->next;
    }
}

int		main(int ac, char **av)
{
  int		i;
  t_exp		*exp;

  i = 1;
  exp = init_elem(av[i]);
  while (av[++i])
    app_name_list(&exp, av[i]);
  show_list(exp);
}
