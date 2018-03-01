/*
** unsigned.c for unsigned in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Thu Nov  5 12:00:30 2015 Florent Sebag
** Last update Mon Nov  9 17:50:15 2015 Florent Sebag
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int		my_put_nbr_un(unsigned int nb)
{
  if (nb > 9)
    my_put_nbr(nb / 10);
  nb = nb % 10 + 48;
  my_putchar(nb);
  return (0);
}

int		my_put_hex_un(unsigned int nb)
{
  int           *result;
  int           i;

  result = malloc(sizeof(int) * 32);
  i = 0;
  while (nb > 0)
    {
      result[i] = (nb % 16);
      nb = nb / 16;
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      if (result[i] < 10)
        my_putchar(result[i] + 48);
      else
        my_putchar(result[i] + 87);
      i = i - 1;
    }
  free(result);
  return (0);
}

int		my_put_long_un(unsigned long nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 9)
    my_put_long(nb / 10);
  nb = nb % 10 + 48;
  my_putchar(nb);
  return (0);
}
