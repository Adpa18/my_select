/*
** str.c for str in /home/wery_a/rendu/Rush_marvin/Test/v3
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Sun Jan  4 16:46:10 2015 adrien wery
** Last update Fri Jan  9 21:01:50 2015 adrien wery
*/

#include "my_select.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_putchr(int c)
{
  write(1, &c, 1);
  return (0);
}

int	my_str(char *s, int mode)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (mode  == 1)
	my_putchar(s[i]);
      i += 1;
    }
  return (i);
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] == s2[i] && s1[i] != '\0' && i < nb)
    i += 1;
  return (s1[i] -s2[i]);
}

char    *my_memset(char *s, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    s[i++] = c;
  return (s);
}
