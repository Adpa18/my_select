/*
** list2.c for list2 in /home/wery_a/rendu/my_select/Test/v6
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Sun Jan 11 13:55:11 2015 adrien wery
** Last update Sun Jan 11 19:33:38 2015 adrien wery
*/

#include "my_select.h"

int                     quit(t_l *list)
{
  int                   a;
  int                   i;

  a = 0;
  i = 0;
  while (list[i].str)
    {
      if (list[i].deleted == 0)
        a +=1;
      i += 1;
    }
  if (a == 0)
    {
      unset_terms(list);
      exit(EXIT_SUCCESS);
    }
  return (1);
}

void                    entrey(t_l *list)
{
  int   i;

  i = 0;
  tputs(tgetstr("cl", NULL), 0, my_putchr);
  unset_terms(list);
  while (list[i].str)
    {
      if (list[i].selected == 1 && list[i].deleted == 0)
        {
          write(0, list[i].str, my_strlen(list[i].str));
          write(0, " ", 1);
        }
      i += 1;
    }
  write(0, "\n", 1);
  exit(EXIT_SUCCESS);
}

int     my_strlen(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    i += 1;
  return (i);
}
