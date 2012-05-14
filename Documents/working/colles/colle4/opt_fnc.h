/*
** opt_fnc.h for opt_get in /home/guillo_e//Documents/working/colles/colle4
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Mon May  7 22:49:02 2012 lyoma guillou
** Last update Mon May  7 22:49:53 2012 lyoma guillou
*/

#ifndef OPT_FNC_H_
# define OPT_FNC_H_

# include "opt_get.h"

t_pos		opt_pos(t_opt *options, const char option);
t_bool		opt_isset(t_opt *options, const char option);

#endif /* !OPT_FNC_H_ */
