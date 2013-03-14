/*
** mem_ptr.c for mem_ptr in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex01
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 09:16:13 2013 lyoma guillou
** Last update Thu Jan 10 12:17:18 2013 lyoma guillou
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mem_ptr.h"

void		add_str(char *str1, char *str2, char **res)
{
  *res = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(**res));
  sprintf(*res, "%s%s", str1, str2);
}

void		add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &(str_op->res));
}
