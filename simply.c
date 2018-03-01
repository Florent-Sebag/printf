/*
** simply.c for si in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Mon Nov  9 17:48:30 2015 Florent Sebag
** Last update Thu Nov 12 19:03:03 2015 Florent Sebag
*/

#include "my.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_put_nbr(int nb)
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
  return (0);
}

int		my_put_long(long nb)
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

int		my_put_percent()
{
  my_putchar('%');
  return (0);
}

int		j_test(int i, int j, const char *str)
{
  if (test_count(str, i - 1) == 2 && j == 3)
    j = j + 8;
  else if (test_count(str, i - 1) == 2 && j == 4)
    {
      if (str[i + 1] == 'd')
	j = j + 2;
      else if (str[i + 1] == 'u')
	j = j + 4;
    }
  return (j);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
