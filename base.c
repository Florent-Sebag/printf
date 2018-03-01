/*
** base.c for ba in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Nov  9 17:19:51 2015 Florent Sebag
** Last update Mon Nov 16 15:36:31 2015 Florent Sebag
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	my_put_hex_cap_va(va_list x)
{
  t_result	res;

  res.result = malloc(sizeof(int) * 32);
  res.i = 0;
  res.nb = va_arg(x, unsigned int);
  if (res.nb == 0)
    my_putchar('0');
  while (res.nb > 0)
    {
      res.result[res.i] = (res.nb % 16);
      res.nb = res.nb / 16;
      res.i = res.i + 1;
    }
  res.i = res.i - 1;
  while (res.i >= 0)
    {
      if (res.result[res.i] < 10)
        my_putchar(res.result[res.i] + 48);
      else
        my_putchar(res.result[res.i] + 55);
      res.i = res.i - 1;
    }
  free(res.result);
  return (0);
}

int		my_put_oct_un_va_o(va_list x)
{
  unsigned int	nb;
  int		*result;
  int		i;

  result = malloc(sizeof(int) * 32);
  i = 0;
  nb = va_arg(x, unsigned int);
  if (nb == 0)
    my_putchar('0');
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
  free(result);
  return (0);
}

int		my_put_hex_un_va(va_list x)
{
  t_result	res;

  res.result = malloc(sizeof(int) * 32);
  res.i = 0;
  res.nb = va_arg(x, unsigned int);
  if (res.nb == 0)
    my_putchar('0');
  while (res.nb > 0)
    {
      res.result[res.i] = (res.nb % 16);
      res.nb = res.nb / 16;
      res.i = res.i + 1;
    }
  res.i = res.i - 1;
  while (res.i >= 0)
    {
      if (res.result[res.i] < 10)
        my_putchar(res.result[res.i] + 48);
      else
        my_putchar(res.result[res.i] + 87);
      res.i = res.i - 1;
    }
  free(res.result);
  return (0);
}

int		my_put_bin_un_va(va_list x)
{
  unsigned int	nb;
  int		*result;
  int		i;

  result = malloc(sizeof(int) * 32);
  i = 0;
  nb = va_arg(x, unsigned int);
  while (nb > 0)
    {
      result[i] = (nb % 2);
      nb = nb / 2;
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      my_putchar(result[i] + 48);
      i = i - 1;
    }
  free(result);
  return (0);
}

int		my_put_ptr(va_list x)
{
  unsigned int	var;

  var = va_arg(x, int);
  if (var == 0)
    {
      my_putstr("(nil)");
      return (0);
    }
  my_putchar('0');
  my_putchar('x');
  my_put_hex_un(var);
  return (0);
}
