/*
** display.c for display in /home/wery_a/rendu/my_select/Test/v4
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan  9 14:00:13 2015 adrien wery
** Last update Fri Jan  9 14:00:48 2015 adrien wery
*/

#include "my_select.h"

int     display_list(t_l *list, int pos, int ws_row, int ws_col)
{
  int   i;
  int   x;
  int   y;
  int   max_s;

  i = 0;
  x = 0;
  y = 0;
  max_s = 0;
  while (list[i].str)
    {
      if (my_str(list[i].str, 0) > max_s)
        max_s = my_str(list[i].str, 0);
      if (y == ws_row)
        {
          x = x + max_s + 1;
          y = 0;
          max_s = 0;
        }
      tputs(tgoto(tgetstr("cm", NULL), x, y), 0, my_putchr);
      if (list[i].deleted != 1)
        y += display_list_2(list, i, pos);
      i += 1;
    }
  return (0);
}

int     display_list_2(t_l *list, int i, int pos)
{
  if (list[i].deleted != 1)
    {
      if (list[i].selected == 1 && i == pos)
        underline(list[i].str);
      else if (list[i].selected == 1)
        r_video(list[i].str);
      else if (i == pos)
        underline(list[i].str);
      else if (list[i].deleted == 0)
        write(0, list[i].str, my_str(list[i].str, 0));
      return (1);
    }
  else
    return (0);
}
