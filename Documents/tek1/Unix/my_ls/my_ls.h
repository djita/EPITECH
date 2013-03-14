/*
** my_ls.h for my_ls in /home/guillo_e//working/unix/my_ls
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Fri Dec  2 16:49:58 2011 lyoma guillou
** Last update Sun Dec  4 06:35:25 2011 lyoma guillou
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <features.h>

typedef	struct	s_data
{
  char		*file_name;
  struct stat	buffer;
  struct passwd	*user;
  struct group	*grp;
  char		time[24];
}		t_data;

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);
void		my_putnbr(int nb);

char		*my_strncpy(char *dst, char *src, int n);

int		is_alpha(char c);
int		is_record(char c);
char		*set_string(char *src);
char		*opt_check(char *str, char *opt);
char		*opt_arg(char **av);

int		is_file_range(char c);
char		*recover_path(char *dst, char *src);
char		**path_name(int ac, char **av);

t_data		*init_data(struct dirent *cur_file);
void		my_put_rights(struct stat mode);
void		block_recover(char *str);
void		data_recover(char *str);

#endif
