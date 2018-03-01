##
## Makefile for ma in /home/sebag_f/Desktop/rendu/PSU_2015_my_printf
##
## Made by Florent Sebag
## Login   <sebag_f@epitech.net>
##
## Started on  Mon Nov  9 17:31:20 2015 Florent Sebag
## Last update Thu Mar  1 16:29:31 2018 Florent Sebag
##

NAME	=	libmy.a

SRC	=	base.c \
		my_printf.c \
		unsigned.c \
		un_va.c \
		va.c \
		simply.c

INCLUDE = include/my.h

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -c

TEMP 	=	$(SRC:.c=.c~)

RM	=	rm -f

PREP	=	ranlib

CREALIB	=	ar rc

all:		$(NAME)

$(NAME):
	$(CC) $(SRC)
	$(CREALIB) $(NAME) $(OBJ)
	$(PREP) $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all


.PHONY:	all re clean fclean
