/*
** key.c for key in /home/wery_a/rendu/my_select/Test/v3
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Thu Jan  8 15:07:09 2015 adrien wery
** Last update Sat Jan 10 14:51:43 2015 adrien wery
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
  return (pos);
}

int	move_pos(t_l *list, int pos, int step, int neg)
{
  pos += neg * step;
  while (list[pos].deleted == 1 || list[pos].finded == 1)
    pos += neg * step;
  return (pos);
}

int     read_key()
{
  char  buff[5];

  my_memset(buff, 0, 5);
  if (read(0, buff, 3) == -1)
    {
      unset_terms();
      my_error("Read Failed");
    }
  if (buff[0] == 27 && buff[1] == 91)
    return (100 + buff[2]);
  else
    return (*buff);

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
