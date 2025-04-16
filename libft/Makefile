NAME= libft.a

SRC = 	ft_atoi.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_bzero.c

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