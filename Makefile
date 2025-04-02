NAME = so_long
BONUS_NAME = so_long_bonus

BONUS_SRCS = bonus/main_bonus.c bonus/parsing_bonus.c bonus/solong_utils_bonus.c bonus/ft_split_bonus.c \
		bonus/check_map_bonus.c bonus/manage_mlx_bonus.c bonus/position_bonus.c \
		bonus/manage_mlx2_bonus.c bonus/itoa.c bonus/manage_mlx3_bonus.c

SRCS = src/main.c src/parsing.c src/solong_utils.c src/ft_split.c src/check_map.c \
		src/manage_mlx.c src/position.c src/manage_mlx2.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(CFLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
