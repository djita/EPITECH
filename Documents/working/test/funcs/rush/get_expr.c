/*
** get_expr.c for marvin in /home/guillo_e//working/test/funcs
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Sat Nov 26 22:11:59 2011 lyoma guillou
** Last update Sun Nov 27 00:13:52 2011 lyoma guillou
*/

int	**(*f)(void)(int a);
B2aAB0c

1		2
code = B2aA	code = B2aAB0c
name = "f"	name = "a";
next-> 2	next->NULL;


typedef struct	s_exp
{
  char		*code;
  char		*name;
  struct s_exp	*next;
}		t_exp;

t_exp		*parcour(t_exp *list)
{
  t_exp		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (bastard == name)
	return (tmp->name);
      tmp = tmp->next;
    }
}

t_exp		*par_rec(t_exp *list)
{
  if (list != NULL)
    {
      par_rec(list->next);

    }

 }
