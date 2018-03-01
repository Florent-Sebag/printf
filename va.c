/*
** va.c for va in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Nov  9 17:34:08 2015 Florent Sebag
** Last update Mon Nov 16 15:13:51 2015 Florent Sebag
*/

#include <stdlib.h>
#include "my.h"

int		my_putchar_va(va_list x)
{
  char		c;

  c = va_arg(x, int);
  write(1, &c, 1);
  return (0);
}

int		my_putstr_va(va_list x)
{
  int		i;
  char		*str;

  str = va_arg(x, char *);
  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int		my_put_nbr_va(va_list x)
{
  int		nb;

  nb = va_arg(x, int);
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  nb = nb * -1;
	}
      if (nb > 9)
	my_put_nbr(nb / 10);
      nb = nb % 10 + 48;
      my_putchar(nb);
    }
  return (0);
}

int		my_put_long_va(va_list x)
{
  long		nb;

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
