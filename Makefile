NAME= fdf

PATH_LIBFT=./libft/
LIBFT=./libft/libft.a

PATH_GNL=./gnl/
GNL=./gnl/get_next_line.a

MINILIB_PATH=./minilibx-linux/
MINILIB=./minilibx-linux/libmlx.a

SRC = 	fdf.c \
	read_map/read_map.c read_map/read_map_utilit.c \
	image/set_image.c image/trace_line.c image/isometric.c image/design.c image/insert_value_z.c\
	create_clear/init_variable.c create_clear/frees.c \
	hooks/hooks.c

CC= cc

CFLAG= -g -Wall -Wextra -Werror

FDFFLAG= -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm  -L -lmlx -lz

OBJ= $(SRC:.c=.o)

all: $(GNL) $(LIBFT) $(MINILIB) $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(GNL) $(LIBFT) $(MINILIB) $(FDFFLAG)  -o $(NAME) 

$(LIBFT):
	@make -C $(PATH_LIBFT)

$(GNL):
	@make -C $(PATH_GNL)

$(MINILIB):
	@make -C $(MINILIB_PATH)

clean:
	rm -rf $(OBJ)
	@make -C $(PATH_LIBFT) clean
	@make -C $(PATH_GNL) clean
	@make -C $(MINILIB_PATH) clean

fclean:clean
	rm -rf $(NAME)
	@make -C $(PATH_LIBFT) fclean
	@make -C $(PATH_GNL) fclean
	@make -C $(MINILIB_PATH) fclean

re: fclean all 


.PHONY: all clean fclean re