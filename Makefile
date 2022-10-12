
SRC =	main.c \
		map.c


OBJ	=	$(SRC:.c=.o)


NAME	=	101pong

all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -lm -o $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur