/*
** un_va.c for unva in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Nov  9 17:39:51 2015 Florent Sebag
** Last update Mon Nov 16 15:46:12 2015 Florent Sebag
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int		my_put_long_un_va(va_list x)
{
  unsigned long	nb;

  nb = va_arg(x, long);
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

int		my_put_nbr_un_va(va_list x)
{
  unsigned int	nb;

  nb = va_arg(x, unsigned int);
  if (nb > 9)
    my_put_nbr(nb / 10);
  nb = nb % 10 + 48;
  my_putchar(nb);
  return (0);
}

int		my_put_oct_un_va_s(va_list x)
{
  char		*str;
  t_result	res;

  res.i = 0;
  res.result = malloc(sizeof(int) * 32);
  str = va_arg(x, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  while (str[res.i] != '\0')
    {
      if (str[res.i] < 32 || str[res.i] >= 127)
	{
	  my_putchar(92);
	  res.nb = str[res.i];
	  my_put_oct(res.nb, res.result);
	}
      else
	my_putchar(str[res.i]);
      res.i = res.i + 1;
    }
  free(res.result);
  return (0);
}

int		my_put_oct(int nb, int *result)
{
  int		i;

  i = 0;
  my_putchar(92);
  while (nb > 0)
    {
      result[i] = (nb % 8);
      nb = nb / 8;
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      my_putchar(result[i] + 48);
      i = i - 1;
    }
  return (0);
}
