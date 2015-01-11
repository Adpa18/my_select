/*
** display.c for display in /home/wery_a/rendu/my_select/Test/v9
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan  9 14:00:13 2015 adrien wery
** Last update Sun Jan 11 23:41:28 2015 adrien wery
*/

#include "my_select.h"

void     display_list(t_l *list, int pos, t_sel se)
{
  int   i;
  int   x;
  int   y;
  int   max_s;

  i = 0;
  x = 3;
  y = 1;
  max_s = 0;
  display_border(se.c, se.r);
  while (list[i].str && display_small(x + max_s, se) != 1 && quit(list) == 1)
    {
      if (my_strlen(list[i].str) > max_s)
        max_s = my_strlen(list[i].str);
      if (y == se.r - 2)
        {
          x = display_col(x + max_s + 1, se.r);
          y = 1;
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
  color_print("\e[00;37m");
  if (match(s, list[i].str) != 0)
    list[i].finded = 1;
  if (list[i].deleted != 1 && list[i].finded != 1)
    {
      if (list[i].selected == 1 && i == pos)
	my_str(list[i].str, 1, "\e[04;35m", "\e[04;37m");
      else if (list[i].selected == 1)
	my_str(list[i].str, 1, "\e[07;37m", "\e[07;37m");
      else if (i == pos)
	my_str(list[i].str, 1, "\e[04;35m", "\e[04;37m");
      else if (list[i].deleted == 0)
	my_str(list[i].str, 1, "\e[01;35m", "\e[00;37m");
      color_print("\e[00;37m");
      return (1);
    }
  else
    return (0);
}

int	display_small(int x, t_sel se)
{
  if ((x > se.c || se.c < 10 || se.r < 4) && se.c < 200)
    {
      tputs(tgetstr("cl", NULL), 0, my_putchr);
      if (se.c < 21)
	write(0, "O", 1);
      else
	write(0, "Window is too small !!!", 21);
      return (1);
    }
  else
    return (0);
}

void	display_numb(t_l *list, int row, int col)
{
  int	i;
  int	selected;
  int	total;

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
  tputs(tgoto(tgetstr("cm", NULL), col - 10, row), 0, my_putchr);
  color_print("\e[01;31m");
  my_put_nbr(selected);
  my_str("/", 1, "\e[01;35m", "\e[00;37m");
  color_print("\e[01;31m");
  my_put_nbr(total);
  color_print("\e[00m");
}

void	display_border(int col, int row)
{
  int	x;

  x = 1;
  color_print("\e[01;33m");
  while (x < row - 2)
    {
      tputs(tgoto(tgetstr("cm", NULL), col - 2, x), 0, my_putchr);
      write(1, "||", 2);
      tputs(tgoto(tgetstr("cm", NULL), 0, x), 0, my_putchr);
      write(1, "||", 2);
      x += 1;
    }
  x = 0;
  color_print("\e[01;34m");
  while (x < col)
    {
      tputs(tgoto(tgetstr("cm", NULL), x, row - 2), 0, my_putchr);
      write(1, "*", 1);
      tputs(tgoto(tgetstr("cm", NULL), x, 0), 0, my_putchr);
      write(1, "*", 1);
      x += 1;
    }
  display_help(col, row);
  color_print("\e[00;37m");
}
