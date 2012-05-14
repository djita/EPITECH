/*
** opt_get.h for opt_get in /home/guillo_e//Documents/working/colles/colle4
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  7 19:13:31 2012 lyoma guillou
** Last update Mon May  7 22:54:32 2012 lyoma guillou
*/

#ifndef OPT_GET_H_
# define OPT_GET_H_

typedef struct	s_opt
{
  char		*arg;
  struct s_opt	*next;
}		t_opt;

typedef int	t_bool;
typedef int	t_pos;

t_opt		*opt_get(int ac, char **av, const char *format);
const char	**opt_args(t_opt *options, const char *option);
void		opt_free(t_opt *options);

t_opt		*list_create(int ac, char **av);

#endif /* !OPT_GET_H_ */
