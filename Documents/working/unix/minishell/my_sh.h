/*
** my_sh.h for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 10:37:43 2011 lyoma guillou
** Last update Fri Feb 10 18:56:12 2012 lyoma guillou
*/

#ifndef MY_SH_
#define MY_SH_

#define	MAX_PATH	20
#define PATH_LEN	40

void	my_putchar(char c);
void	my_putstr(char *str);

void	*my_memset(void *buffer, int s, int len);

char	*get_path(char **my_env);
char	**path_tab(char *cmd, char *path);
char	**insert_cmd(char **path_list);

void	call_exec(char *cmd, char **arg, char **env);
void	cmd_to_exec(char *src, char **env);

int	my_strlen(char *str);
int	my_strncmp(char *src, char *dst, int len);
char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *src);

int	is_alphanum(char c);
int	word_len(char *str, int cursor);
int	word_to_cell(char *tab, char *str, int cursor);
int	count_words(char *str);
char	**my_str_to_wordtab(char *str);

#endif
