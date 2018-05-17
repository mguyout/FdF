NAME = fdf

all : $(NAME)

FLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework Appkit -Ofast -mtune=native 

CONVC = $(SRC:.c=.o)

SRC = main.c \
	  create_map.c \
	  draw_map.c \
	  hook.c

$(NAME):
	Make -C Libft/
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(MLX) minilibx_macos\ 3/libmlx.a libft/libft.a $(SRC) -o $(NAME)

clean :
	make -C libft/ clean
	rm -rf $(CONVC)

fclean : clean
	make -C libft/ fclean
	rm -rf $(CONVC) fdf

re : fclean all

.PHONY : all clean re fclean
