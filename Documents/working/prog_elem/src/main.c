/*
** main.c for lem-in in /home/guillo_e//Documents/working/prog_elem/src
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Mar 30 17:03:27 2012 lyoma guillou
** Last update Tue Apr 10 18:33:05 2012 lyoma guillou
*/

#define	STDIN	0

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <parse.h>

t_list		get_file_data(int fd)
{
  t_list	list;
  t_room	*r_tmp;
  t_pipe	*p_tmp;
  char		*line;
  char		**tab;

  line = 0;
  list = init_list();
  tab = 0;
  while ((line = get_next_line(fd)))
    {
      if (line[0] != '#' && my_strlen(line) >= 3)
	{
	  tab = my_str_to_wordtab(line);
	  if (tab && my_tablen(tab) == 3)
	    {
	      r_tmp = get_room(tab);
	      list = append_room(list, r_tmp);
	    }
	  else if (tab && my_tablen(tab) == 2)
	    {
	      p_tmp = get_pipe(tab);
	      list = append_pipe(list, p_tmp);
	    }
	}
      free(line);
    }
  return (list);
}

int		main()
{
  t_list	list;
  t_room	*r_tmp;
  t_room	*r_free;
  t_pipe	*p_tmp;
  t_pipe	*p_free;

  list = get_file_data(STDIN);
  r_tmp = list.r_first;
  while (r_tmp != NULL)
    {
      printf("Name: %s, X: %i, Y: %i\n", r_tmp->name, r_tmp->x_pos, r_tmp->y_pos);
      r_free = r_tmp;
      r_tmp = r_tmp->next;
      free(r_free);
    }
  p_tmp = list.p_first;
  while (p_tmp != NULL)
    {
      printf("Entry: %s, Exit:%s\n", p_tmp->entry, p_tmp->exit);
      p_free = p_tmp;
      p_tmp = p_tmp->next;
      free(p_free);
    }
  return (0);
}
