/*
** my.h for h in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
** 
** Made by Florent Sebag
** Login   <sebag_f@epitech.net>
** 
** Started on  Wed Nov  4 16:52:54 2015 Florent Sebag
** Last update Mon Nov 16 15:28:52 2015 Florent Sebag
*/

#ifndef MY_H_
# define LIST_H_
#include <stdarg.h>

typedef	struct	s_type
{
  int		(*ptr)(va_list);
  char		*flags;
}		t_type;

typedef	struct	s_var
{
  int		i;
  int		j;
  int		k;
}		t_var;

typedef struct	s_result
{
  int		i;
  int		*result;
  unsigned int	nb;
}		t_result;

void		my_putstr(char *str);
int		my_put_oct(int nb, int *result);
int		my_putchar_va(va_list x);
int		my_putstr_va(va_list x);
int		my_put_nbr_va(va_list x);
int		my_put_nbr(int nb);
void		my_putchar(char c);
int		my_put_long_va(va_list x);
int		my_put_long(long nb);
int		my_put_short_va(va_list x);
int		my_put_short(short nb);
int		my_put_nbr_un_va(va_list x);
int		my_put_nbr_un(unsigned int nb);
int		my_put_bin_un_va(va_list x);
int		my_put_long_un_va(va_list x);
int		my_put_long_un(unsigned long nb);
int		my_put_hex_un_va(va_list x);
int		my_put_oct_un_va_o(va_list x);
int		my_put_oct_un_va_s(va_list x);;
int		my_put_hex_un(unsigned int nb);
int		my_put_ptr(va_list x);
int		my_put_hex_cap_va(va_list x);
int		check_letters(char c);
int		my_put_percent();
int		j_test(int i, int j, const char *format);
int             error(const char *str, ...);

#endif /* !MY_H_ */
