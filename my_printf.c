/*
** my_printf.c for i in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Tue Nov  3 17:26:26 2015 Florent Sebag
** Last update Mon Nov 16 15:02:49 2015 Florent Sebag
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static t_type	tab[] =
  {
    {&my_putchar_va, "c"},
    {&my_putstr_va, "s"},
    {&my_put_nbr_va, "i"},
    {&my_put_percent, "h"},
    {&my_put_percent, "l"},
    {&my_put_nbr_va, "d"},
    {&my_put_long_va, "ld"},
    {&my_put_nbr_un_va, "u"},
    {&my_put_long_un_va, "lu"},
    {&my_put_ptr, "p"},
    {&my_put_percent, "%"},
    {&my_put_nbr_va, "hd"},
    {&my_put_nbr_un_va, "hu"},
    {&my_put_hex_un_va, "x"},
    {&my_put_bin_un_va, "b"},
    {&my_put_oct_un_va_s, "S"},
    {&my_put_hex_cap_va, "X"},
    {&my_put_oct_un_va_o, "o"},
    {0, NULL}
  };

void		print_var(const char *format, va_list x)
{
  t_var		count;

  count.i = 0;
  count.j = 0;
  while (format[count.i] != '\0')
    {
      if (format[count.i] == '%' && check_letters(format[count.i + 1]) == 0)
	{
	  while (tab[count.j].flags[0] != format[count.i + 1])
	    count.j = count.j + 1;
	  count.j = j_test(count.i + 1, count.j, format);
	  tab[count.j].ptr(x);
	  count.i = count.i + test_count(format, count.i);
	}
      else if (format[count.i] == '%' && check_letters(format[count.i + 1]) == 1)
	count.i = count.i + 1;
      else
	my_putchar(format[count.i]);
      count.j = 0;
      count.i = count.i + 1;
    }
  va_end(x);
}

int		test_count(char *str, int i)
{
  if (str[i + 1] == 'h' && (str[i + 2] == 'd' || str[i + 2] == 'u'))
    return (2);
  else if ((str[i + 1] == 'l') && (str[i + 2] == 'd' || str[i + 2] == 'u'))
    return (2);
  else
    return (1);
}

int		check_letters(char c)
{
  int		i;

  i = 0;
  while (tab[i].flags[0] != c && i < 17)
    i = i + 1;
  if (i == 17)
    {
      if (c != 'o')
	i = i + 1;
      else
	return (0);
    }
  else if (i == 18)
    {
      my_putchar('%');
      my_putchar(c);
      return (1);
    }
  else
    return (0);
}

int		my_printf(const char *format, ...)
{
  va_list	x;

  va_start(x, format);
  if (format == NULL)
    return (0);
  else
    print_var(format, x);
  return (0);
}
