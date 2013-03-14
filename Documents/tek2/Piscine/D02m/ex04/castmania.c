/*
** castmania.c for castmania in /home/guillo_e//Documents/working/tek2/piscine/D02m/ex04
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Thu Jan 10 10:43:07 2013 lyoma guillou
** Last update Thu Jan 10 12:13:49 2013 lyoma guillou
*/

#include <stdio.h>
#include "castmania.h"

void		exec_operation(t_instruction_type instruction_type, void *data)
{
  t_instruction	*dock;
  t_add		*add;
  t_div		*div;

  dock = data;
  switch (instruction_type)
    {
    case ADD_OPERATION:
      add = dock->operation;
      exec_add(add);
      if (dock->output_type == VERBOSE)
	printf("%d\n", add->add_op.res);
      break;
    case DIV_OPERATION:
      div = dock->operation;
      exec_div(div);
      if (dock->output_type == VERBOSE)
	{
	  if (div->div_type == DECIMALE)
	    {
	      t_decimale_op	*op = div->div_op;
	      printf("%f\n", op->res);
	    }
	  else
	    {
	      t_integer_op	*op = div->div_op;
	      printf("%d\n", op->res);
	    }
	}
      break;
    default :
      break;
    }
}

void		exec_instruction(t_instruction_type instruction_type, void *data)
{
  int		*num;
  float		*dec;

  switch (instruction_type)
    {
    case PRINT_INT:
      num = data;
      printf("%d\n", *num);
      break;
    case PRINT_FLOAT:
      dec = data;
      printf("%f\n", *dec);
      break;
    default :
      exec_operation(instruction_type, data);
    }
}
