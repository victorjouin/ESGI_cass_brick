
SRC =	main.c		\
		player.c	\
		map.c		\
		menu.c		\
		bomb.c


OBJ	=	$(SRC:.c=.o)


LDFLAGS= -lncurses

NAME	=	play

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -lm -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur