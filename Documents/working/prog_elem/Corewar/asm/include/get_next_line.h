/*
** get_next_line.h for include in /home/czegan_g/project/current/corewar/asm/include
**
** Made by louis duverdier
** Login   <duverd_l@epitech.net>
**
** Started on  Fri Jan 20 14:22:10 2012 louis duverdier
** Last update ven. mars 23 00:38:32 2012 gaby czegany
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include       <unistd.h>
# include       <stdlib.h>
# include       <my.h>

# define MAX_CHAR_READ          19999
# define BUFFER_MAX_SIZE        20000

char	*get_next_line(const int);

#endif
