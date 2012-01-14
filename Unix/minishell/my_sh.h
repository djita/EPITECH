/*
** my_sh.h for my_sh in /home/guillo_e//working/unix/minishell
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Dec 21 10:37:43 2011 lyoma guillou
** Last update Sun Jan  1 22:17:23 2012 lyoma guillou
*/

#ifndef MY_SH_
#define MY_SH_

char	**copy_envp(char **envp);
char	*get_path(char **my_env);

void	call_exec(char *cmd, char **arg, char **env);
void	cmd_to_exec(char *src, char **env);

int	my_tablen(char **tab);
char	**my_tabset(char **tab, int len);

char	*my_strdup(char *src);
char	*my_strset(char *str, int lim);
int	my_strcmp(char *src, char *dst);
int	my_strncmp(char *src, char *dst, int len);

void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(char *str);
char	*my_strfus(char *str, char *ptr);

int	is_alphanum(char c);
int	word_len(char *str, int cursor);
int	word_to_cell(char *tab, char *str, int cursor);
int	count_words(char *str);
char	**my_str_to_wordtab(char *str);

#endif
