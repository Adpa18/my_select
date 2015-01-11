/*
** str2.c for str2 in /home/wery_a/rendu/my_select/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:26:44 2015 adrien wery
** Last update Sun Jan 11 20:09:19 2015 adrien wery
*/

#include "my_select.h"

void     my_error(char *s)
{
  my_str(s, 1, NULL, NULL);
  exit(EXIT_FAILURE);
}

void    *my_malloc(int size)
{
  char  *str;

  if ((str = malloc(size)) == NULL)
    my_error("Malloc Failed");
  my_memset(str, 0, size);
  return (str);
}

int     cal(int nb, int n)
{
  if (n > 9)
    {
      nb = n % 10;
      cal(nb, n / 10);
    }
  else
    nb = n;
  my_putchar(nb + 48);
  return (nb);
}

void     my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
      cal(nb, nb);
    }
  else
    cal(nb, nb);
}

void     color_print(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      my_putchar(s[i]);
      i += 1;
    }
}
