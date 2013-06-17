##
## Makefile for Makefile in /home/loverg_c//RATTRAPAGE
## 
## Made by clement lovergne
## Login   <loverg_c@epitech.net>
## 
## Started on  Mon Jun 17 10:30:44 2013 clement lovergne
## Last update Mon Jun 17 19:36:26 2013 clement lovergne
##

NAME=		Robby

COMP=		gcc -o

RM=		rm -f

SRC=		robby/main.c				\
		robby/parser.c				\
		my_fonction/get_next.c			\
		my_fonction/usualfonction.c		\
		my_fonction/usualfonction2.c		\
		robby/telephone/telephone.c		\
		robby/telephone/error_tel.c		\
		robby/telephone/pars_config.c		\
		robby/vaccum/vaccum.c			\
		robby/kitchen/kitchen.c

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