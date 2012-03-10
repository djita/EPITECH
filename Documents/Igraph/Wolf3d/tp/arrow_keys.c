/*
** arrow_keys.c for wolf3d in /home/guillo_e//working/igraph/tp
** 
** Made by lyoma guillou
** Login   <guillo_e@epitech.net>
** 
** Started on  Wed Jan 11 11:29:22 2012 lyoma guillou
** Last update Wed Jan 11 11:53:17 2012 lyoma guillou
*/

#include "key.h"

int		up_arrow(int keycode)
{
  if (UARW == keycode)
    return (keycode);
  return (0);
}

int		down_arrow(int keycode)
{
  if (DARW == keycode)
    return (keycode);
  return (0);
}

int		right_arrow(int keycode)
{
  if (RARW == keycode)
    return (keycode);
  return (0);
}

int		lef_arrow(int keycode)
{
  if (LARW == keycode)
    return (keycode);
  return (0);
}

int		arrow_keys(int keycode)
{
  int		key;

  key = 0;
  if ((key = up_arrow(keycode)))
    return (key);
  if ((key = down_arrow(keycode)))
    return (key);
  if ((key = right_arrow(keycode)))
    return (key);
  if ((key = lef_arrow(keycode)))
    return (key);
  return (key);
}
