/*
** str_to_wordtab.h for 42sh in /home/bonmar_v//Projets/SVN/42sh
** 
** Made by vincent bonmarchand
** Login   <bonmar_v@epitech.net>
** 
** Started on  Sun May 20 20:08:34 2012 vincent bonmarchand
** Last update Sun May 20 22:34:24 2012 lyoma guillou
*/

#ifndef  STR_TO_WORDTAB_H_
# define STR_TO_WORDTAB_H_

typedef struct	s_word_flag
{
  char		*tmp;
  int		match;
  int		cnt;
  char		sym;
}		t_word_flag;

char	**str_to_wordtab(char *str);
char	*free_tab(char **tab);

#endif /* !ENDIF */
