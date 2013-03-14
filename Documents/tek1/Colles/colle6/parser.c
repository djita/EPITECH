/*
** main.c for main in /home/deleta_m//Projets/Colles/Colle_6
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 21 19:10:25 2012 marc deletang
** Last update Mon May 21 22:51:57 2012 marc deletang
*/

#include <stdlib.h>
#include <unistd.h>
#include "carre.h"
#include "utils.h"

static void	_init_player1(t_players **players, char *str)
{
  int		i;
  int		j;
  char		*str_tmp;

  i = 0;
  j = 0;
  (*players)->name_p1 = xmalloc(my_strlen(str) + 1);
  while (str[i] && str[i] != ':')
    {
      (*players)->name_p1[i] = str[i];
      i++;
    }
  if (str[i])
    i++;
  str_tmp = xmalloc(my_strlen(str) + 1);
  while (str[i])
    str_tmp[j++] = str[i++];
  str_tmp[j] = '\0';
  (*players)->color_p1 = my_getnbr_base(str_tmp, "0123456789ABCDEF");
  if ((*players)->color_p1 <= 0)
    (*players)->color_p1 = PC1(0);
  free(str_tmp);
}

static void	_init_player2(t_players **players, char *str)
{
  int		i;
  int		j;
  char		*str_tmp;

  i = 0;
  j = 0;
  (*players)->name_p2 = xmalloc(my_strlen(str) + 1);
  while (str[i] && str[i] != ':')
    {
      (*players)->name_p2[i] = str[i];
      i++;
    }
  if (str[i])
    i++;
  str_tmp = xmalloc(my_strlen(str) + 1);
  while (str[i])
    str_tmp[j++] = str[i++];
  str_tmp[j] = '\0';
  (*players)->color_p2 = my_getnbr_base(str_tmp, "0123456789ABCDEF");
  if ((*players)->color_p2 <= 0)
    (*players)->color_p2 = PC2(0);
  free(str_tmp);
}

static void	_parse_av(t_players **players, t_pos *size, char **av)
{
  int		i;

  i = 1;
  while (av[i])
    {
      if (!my_strcmp(av[i], "-l") && av[i + 1])
	size->x = my_getnbr(av[i + 1]);
      if (!my_strcmp(av[i], "-L") && av[i + 1])
	size->y = my_getnbr(av[i + 1]);
      if (!my_strcmp(av[i], "-1") && av[i + 1])
	_init_player1(players, av[i + 1]);
      if (!my_strcmp(av[i], "-2") && av[i + 1])
	_init_player2(players, av[i + 1]);
      i++;
    }
  if (size->x <= 1)
    size->x = 10;
  if (size->y <= 1)
    size->y = 10;
}

void		init_argv(t_players **players, t_pos *size, char **av)
{
  size->x = 10;
  size->y = 10;
  (*players)->name_p1 = my_strdup("Player 1");
  (*players)->name_p2 = my_strdup("Player 2");
  (*players)->color_p1 = PC1(0);
  (*players)->color_p2 = PC2(0);
  (*players)->turn = 1;
  _parse_av(players, size, av);
}
