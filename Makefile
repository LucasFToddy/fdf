NAME= fdf
PATH_PRINTF=./ft_printf/
PRINTF=./ft_printf/ft_printf.a

PATH_LIBFT=./libft/
LIBFT=./libft/libft.a

PATH_GNL=./gnl/
GNL=./gnl/get_next_line.a

MINILIB_PATH=./minilibx-linux/
MINILIB=./minilibx-linux/libmlx.a

SRC = 	fdf.c read_map/read_map.c image/set_image.c image/trace_line.c image/isometric.c image/design.c hooks/hooks.c create_clear/create_and_clear.c

CC= cc

CFLAG= -g -Wall -Wextra -Werror

FDFFLAG= -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm  -L -lmlx -lz

OBJ= $(SRC:.c=.o)

all: $(PRINTF) $(GNL) $(LIBFT) $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(PRINTF) $(GNL) $(LIBFT) $(MINILIB) $(FDFFLAG)  -o $(NAME) 

$(PRINTF): 
	@make -C $(PATH_PRINTF)

$(LIBFT):
	@make -C $(PATH_LIBFT)

$(GNL):
	@make -C $(PATH_GNL)

$(MINILIB):
	@make -C $(MINILIB_PATH)

clean:
	rm -rf $(OBJ)
	@make -C $(PATH_PRINTF) clean
	@make -C $(PATH_LIBFT) clean
	@make -C $(PATH_GNL) clean

fclean:clean
	rm -rf $(NAME)
	@make -C $(PATH_PRINTF) fclean
	@make -C $(PATH_LIBFT) fclean
	@make -C $(PATH_GNL) fclean

re: fclean all 


.PHONY: all clean fclean re