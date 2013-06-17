##
## Makefile for Makefile in /home/loverg_c//RATTRAPAGE
## 
## Made by clement lovergne
## Login   <loverg_c@epitech.net>
## 
## Started on  Mon Jun 17 10:30:44 2013 clement lovergne
## Last update Mon Jun 17 13:46:27 2013 clement lovergne
##

NAME=		Robby

COMP=		gcc -o

RM=		rm -f

SRC=		main.c			\
		get_next.c		\
		usualfonction.c		\
		usualfonction2.c	\
		telephone.c		\
		error_tel.c		\
		pars_config.c		\
		vaccum.c		\
		kitchen.c

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