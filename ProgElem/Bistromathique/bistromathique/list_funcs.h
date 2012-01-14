/*
** list_funcs.h for bistromathique in /afs/epitech.net/users/epitech_2016/falck_m/public/prog_elem/bistromathique
** 
** Made by mickael falck
** Login   <falck_m@epitech.net>
** 
** Started on  Wed Nov 02 15:06:28 2011 mickael falck
** Last update Sat Nov 05 11:49:46 2011 mickael falck
*/

#ifndef LIST_FUNCS_H_
#  define LIST_FUNCS_H_

int		is_ops(char c, char *ops);
int		is_base(char c, char *base);
t_oper		*init_list(char op);
t_oper		*app_in_list(t_oper *link, char op);
t_oper		*operand_to_list(char *str);
void		read_list(t_oper *first_link);

#endif /* !LIST_FUNCS_H_ */
