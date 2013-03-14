/*
** String.h for String in /home/guillo_e//Documents/working/tek2/piscine/D03/ex00
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Jan 11 09:04:12 2013 lyoma guillou
** Last update Fri Jan 11 11:44:25 2013 lyoma guillou
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct	s_string
{
  char		*str;
  void		(*assign_s)(struct s_string *, struct s_string const *);
  void		(*assign_c)(struct s_string *, char const *);
  void		(*append_s)(struct s_string *, struct s_string const *);
  void		(*append_c)(struct s_string *, char const *);
  char		(*at)(struct s_string *, size_t);
  void		(*clear)(struct s_string *);
  int		(*size)(struct s_string *);
  int		(*compare_s)(struct s_string *, const struct s_string *);
  int		(*compare_c)(struct s_string *, char const *);
}		String;

void		StringInit(String *this, char const *s);
void		StringDestroy(String *this);

#endif
