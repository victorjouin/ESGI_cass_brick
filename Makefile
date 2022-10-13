
SRC =	main.c \
		map.c


OBJ	=	$(SRC:.c=.o)


LDFLAGS= -lncurses

NAME	=	101pong

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