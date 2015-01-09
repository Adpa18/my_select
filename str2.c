/*
** str2.c for str2 in /home/wery_a/rendu/my_select/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Wed Jan  7 14:26:44 2015 adrien wery
** Last update Thu Jan  8 14:59:30 2015 adrien wery
*/

#include "my_select.h"

void     my_error(char *s)
{
  if (printf("%s\n", s) < 0)
    printf("Error with printf during an error return !!!\n");
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
