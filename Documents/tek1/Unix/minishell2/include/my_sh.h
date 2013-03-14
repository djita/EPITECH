/*
** my_sh.h for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 10:37:43 2011 lyoma guillou
** Last update Sat Mar  3 21:57:36 2012 lyoma guillou
*/

#ifndef MY_SH_
#define MY_SH_

#define ENV_SIZE	50
#define	MAX_PATH	20
#define PATH_LEN	40
#define	BUFF_SIZE	4096
#define	MAX_BLT		4

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct	s_built
{
  char		*cmd;
  int		(*fnc)(char **, char **);
}		t_built;

int		xwrite(int fd, void *ptr, int size);
void		*xmalloc(int);

void		my_putchar(char);
int		my_strlen(char *);
void		my_putstr(char *);
void		my_puterr(char *);

void		*my_memset(void *, int, int);
void		*my_memcpy(void *dst, void *src, int len);

char		*get_path(char **);
char		*my_getenv(char *, char **);

char		**copy_envp(char **);
char		**path_tab(char *, char *);
char		**insert_cmd(char **);
void		shell_init(char **);

int		_exit_built(char **, char **);
int		_set_env(char **, char **);
int		_unset_env(char **, char **);
int		_ch_dir(char **, char **);

int		cmd_to_exec(char *, char **);

int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strcpy(char *, char *);
char		*my_strcat(char *, char *);
char		*my_strdup(char *);

int		my_tablen(char **);
void		my_showtab(char **);

char		**my_str_to_wordtab(char *);

void		handle_signal(int);

#endif
