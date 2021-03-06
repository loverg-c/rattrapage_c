##
## Makefile for Makefile in /home/loverg_c//RATTRAPAGE
## 
## Made by clement lovergne
## Login   <loverg_c@epitech.net>
## 
## Started on  Mon Jun 17 10:30:44 2013 clement lovergne
## Last update Tue Jun 25 10:50:15 2013 clement lovergne
##

NAME=		Robby

COMP=		gcc -o

RM=		rm -f

SRC=		robby/main.c				\
		robby/parser.c				\
		my_fonction/usualfonction.c		\
		my_fonction/usualfonction2.c		\
		my_fonction/usualfonction3.c		\
		robby/telephone/telephone.c		\
		robby/telephone/error_tel.c		\
		robby/telephone/pars_config.c		\
		robby/vaccum/vaccum.c			\
		robby/vaccum/draw_room.c		\
		robby/vaccum/parser_vaccum.c		\
		robby/vaccum/robby_and_vaccum.c		\
		robby/vaccum/display_vaccum.c		\
		robby/kitchen/kitchen.c			\
		robby/kitchen/list.c			\
		robby/kitchen/count_ingredients.c	\
		robby/kitchen/choose.c			\
		robby/kitchen/check_types.c		\
		robby/kitchen/sub.c			\
		robby/kitchen/menu_kitchen.c		\
		robby/kitchen/pars_kitchen.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-g -Wall -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all