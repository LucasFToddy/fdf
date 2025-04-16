NAME= ft_printf.a

SRC= ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putnbr_ptr.c ft_putnbr.c ft_putstr.c

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
