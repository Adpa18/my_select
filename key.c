/*
** key.c for key in /home/wery_a/rendu/my_select/Test/v3
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Thu Jan  8 15:07:09 2015 adrien wery
** Last update Sun Jan 11 15:02:39 2015 adrien wery
*/

#include "my_select.h"

int	check_key(t_l *list, int key, int pos)
{
  if (key == DOWN_KEY)
    pos = move_pos(list, pos, 1, 1);
  if (key == UP_KEY)
    pos = move_pos(list, pos, 1, -1);
  if (key == SPACE_KEY && list[pos].selected != 1)
    list[pos++].selected = 1;
  else if (key == SPACE_KEY && list[pos].selected != 0)
    list[pos].selected = 0;
  if (key == SUPP_KEY)
    list[pos++].deleted = 1;
  if (key == RIGHT_KEY)
    restore_list(list);
  if (key == LEFT_KEY)
    inverse_selected(list);
  if (key == BEGIN_KEY)
    selected_all(list);
  if (key == END_KEY)
    deselected_all(list);
  return (pos);
}

int	move_pos(t_l *list, int pos, int step, int neg)
{
  pos += neg * step;
  while (list[pos].deleted == 1 || list[pos].finded == 1)
    pos += neg * step;
  return (pos);
}

int     read_key(t_l *list)
{
  char  buff[5];

  my_memset(buff, 0, 4);
  if (read(0, buff, 5) == -1)
    {
      unset_terms(list);
      my_error("Read Failed");
    }
  return (buff[0] + buff[1] + buff[2] + buff[3]);
}

int	get_pos(t_l *list, int pos)
{
  int	i;

  i = 0;
  while (list[i].str)
    i += 1;
  if (pos < 0)
    pos = i - pos * -1;
  else
    pos = pos % i;
  return (pos);
}
