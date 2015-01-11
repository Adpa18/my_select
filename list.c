/*
** list.c for list in /home/wery_a/rendu/my_select/Test/v4
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan  9 14:04:00 2015 adrien wery
** Last update Sun Jan 11 17:35:47 2015 adrien wery
*/

#include "my_select.h"

t_l     *set_list(int ac, char **av)
{
  t_l   *list;
  int   i;

  i = 0;
  if ((list = malloc(sizeof(t_l) * (ac + 1))) == NULL)
    my_error("Malloc Failed !!!");
  while (i < ac - 1)
    {
      list[i].str = av[i + 1];
      i += 1;
    }
  list[i].str = NULL;
  i = 0;
  while (list[i].str)
    {
      list[i].selected = 0;
      list[i].deleted = 0;
      list[i].finded = 0;
      i += 1;
    }
  return (list);
}

void    restore_list(t_l *list)
{
  int   i;

  i = 0;
  while (list[i].str)
    {
      list[i].deleted = 0;
      list[i].finded = 0;
      list[i].selected = 0;
      i += 1;
    }
}

void    inverse_selected(t_l *list)
{
  int   i;

  i = 0;
  while (list[i].str)
    {
      if (list[i].selected == 1 && list[i].deleted == 0)
	list[i].selected = 0;
      else if (list[i].selected == 0 && list[i].deleted == 0)
	list[i].selected = 1;
      i += 1;
    }
}

void    selected_all(t_l *list)
{
  int   i;

  i = 0;
  while (list[i].str)
    {
      if (list[i].deleted == 0)
	list[i].selected = 1;
      i += 1;
    }
}

void    deselected_all(t_l *list)
{
  int   i;

  i = 0;
  while (list[i].str)
    {
      if (list[i].deleted == 0)
	list[i].selected = 0;
      i += 1;
    }
}
