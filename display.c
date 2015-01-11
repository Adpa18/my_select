/*
** display.c for display in /home/wery_a/rendu/my_select/Test/v4
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan  9 14:00:13 2015 adrien wery
** Last update Sun Jan 11 15:30:56 2015 adrien wery
*/

#include "my_select.h"

void     display_list(t_l *list, int pos, t_sel se)
{
  int   i;
  int   x;
  int   y;
  int   max_s;

  i = 0;
  x = 0;
  y = 0;
  max_s = 0;
  while (list[i].str && display_small(x + max_s, se.c) != 1 && quit(list) == 1)
    {
      if (my_str(list[i].str, 0) > max_s)
        max_s = my_str(list[i].str, 0);
      if (y == se.r - 2)
        {
          x = x + max_s + 1;
          y = 0;
          max_s = 0;
        }
      tputs(tgoto(tgetstr("cm", NULL), x, y), 0, my_putchr);
      if (list[i].deleted != 1 && list[i].finded != 1)
        y += display_list_2(list, i, pos, se.s);
      i += 1;
    }
}

int     display_list_2(t_l *list, int i, int pos, char *s)
{
  if (strncmp(s, list[i].str, my_str(s, 0)) != 0)
    list[i].finded = 1;
  if (list[i].deleted != 1 && list[i].finded != 1)
    {
      if (list[i].selected == 1 && i == pos)
        underline(list[i].str);
      else if (list[i].selected == 1)
        r_video(list[i].str);
      else if (i == pos)
        underline(list[i].str);
      else if (list[i].deleted == 0)
        write(1, list[i].str, my_str(list[i].str, 0));
      return (1);
    }
  else
    return (0);
}

int	display_small(int x, int ws_col)
{
  if (x > ws_col)
    {
      tputs(tgetstr("cl", NULL), 0, my_putchr);
      if (ws_col < 21)
	write(0, "O", 1);
      else
	write(0, "Window is too small !!!", 21);
      return (1);
    }
  else
    return (0);
}

void                    display_numb(t_l *list)
{
  int                   i;
  int                   selected;
  int                   total;

  i = 0;
  selected = 0;
  total = 0;
  while (list[i].str)
    {
      if (list[i].deleted == 0)
        {
          if (list[i].selected == 1)
            selected += 1;
          total += 1;
        }
      i += 1;
    }
  tputs(tgoto(tgetstr("cm", NULL), 100, 100), 0, my_putchr);
  my_put_nbr(selected);
  my_str(" / ", 1);
  my_put_nbr(total);
}
