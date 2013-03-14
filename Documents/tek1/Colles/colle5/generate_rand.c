/*
** generate_rand.c for generate_rand in /home/deleta_m//Projets/Colles/Colle_5
** 
** Made by marc deletang
** Login   <deleta_m@epitech.net>
** 
** Started on  Mon May 14 20:36:45 2012 marc deletang
** Last update Mon May 14 21:48:52 2012 lyoma guillou
*/

#include <time.h>
#include <stdlib.h>
#include "game_of_life.h"

int		generate_rand(int size)
{
  time_t	val_time;
  int		val_random;

  val_time = 0;
  val_time = time(&val_time);
  srand(val_time);
  val_random = rand();
  val_random = val_random % size;
  return (val_random);
}
