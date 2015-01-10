/*
** list.c for list in /home/wery_a/rendu/my_select/Test/v4
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Jan  9 14:04:00 2015 adrien wery
** Last update Sat Jan 10 14:40:25 2015 adrien wery
*/

#include "my_select.h"

t_l     *set_list(char **s)
{
  t_l   *list;
  int   i;
  int   size;

  i = 0;
  while (s[i])
    i += 1;
  if ((list = malloc(sizeof(t_l) * (i + 1))) == NULL)
    my_error("Malloc Failed !!!");
  size = i;
  i = 0;
  while (i != size)
    {
      list[i].str = s[i];
      list[i].selected = 0;
      list[i].deleted = 0;
      list[i].finded = 0;
      i += 1;
    }
  list[i].str = NULL;
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

void	sigw2(int sig)
{
  my_putchr(sig);
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  unset_terms();
  exit(EXIT_SUCCESS);
}
