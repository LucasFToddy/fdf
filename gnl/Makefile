NAME= get_next_line.a

SRC = 	get_next_line.c get_next_line_utils.c 

CC= cc

CFLAG= -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME) 

re: fclean all

run:
	clear
	$(CC) $(CFLAG) main.c $(NAME)
	./a.out

.PHONY: all clean fclean re