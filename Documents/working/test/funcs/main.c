/*
** main.c for my_str_to_wordtab in /home/guillo_e//working/test/funcs
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Oct 19 18:23:49 2011 lyoma guillou
** Last update Sun Nov 27 20:50:55 2011 lyoma guillou
*/

#include <stdio.h>

int		main(int ac, char **av)
{
  int		stx;
  
  stx = end_dec(av[1]);
  if (stx != 0)
    printf("Erreur de syntaxe à la colonne = %d\n", stx);
  return (0);
}
