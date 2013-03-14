/*
** parsing.h for parsing in /home/deleta_m//Projets/Colles/Colle_4
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May  7 20:29:34 2012 marc deletang
** Last update Mon May  7 22:56:51 2012 lyoma guillou
*/

#ifndef PARSING_H_
# define PARSING_H_

typedef struct		s_option
{
  char			name;
  int			needed;
  int			compress;
  int			arg_min;
  int			find;
  struct s_option	*next;
}			t_option;

void			free_opts(t_option *list);
t_option		*new_elem();
t_option		*append_to_opt(t_option *list, t_option *new);
t_option		*create_options(char *str);

#endif /* !PARSING_H_ */
