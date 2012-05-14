/*
** reader.h for my_reader in /home/guillo_e//Documents/working/colles/colle2
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Tue Apr 24 19:23:38 2012 lyoma guillou
** Last update Tue Apr 24 22:41:21 2012 lyoma guillou
*/

#ifndef READER_H_
# define READER_H_

enum		dat
  {
    START,
    END,
    TEXT
  };

typedef struct	s_obj
{
  char		*type;
  char		*content;  
  struct s_obj	*next;
}		t_obj;

typedef struct	s_data
{
  char		*name;
  t_obj		*item;
  struct s_data	*next;
}		t_data;

t_obj		*new_elem();
t_obj		*append_obj(t_obj *list, t_obj *new);
t_data		*new_data();
t_data		*append_data(t_data *list, t_data *new);

t_data		**get_info(char *str, t_data **data);

#endif
