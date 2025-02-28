NAME = so_long

BONUS_NAME = so_long_bonus

BONUS_SRCS = bonus/main_bonus.c bonus/parsing_bonus.c bonus/solong_utils_bonus.c bonus/ft_split_bonus.c \
			bonus/check_map_bonus.c bonus/manage_mlx_bonus.c bonus/position_bonus.c \
			bonus/manage_mlx2_bonus.c bonus/itoa.c bonus/manage_mlx3_bonus.c

SRCS = main.c parsing.c solong_utils.c ft_split.c check_map.c \
		manage_mlx.c position.c manage_mlx2.c

OBJS:= $(SRCS:.c=.o)
BONUS_OBJS:= $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

bonus:$(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L /usr/include/minilibx-linux -Imlx_linux -lXext -lX11  -lz -o $(NAME)

BONUS_OBJS:= $(BONUS_SRCS:.c=.o)

$(BONUS_NAME):$(BONUS_OBJS) bonus/so_long_bonus.h
	$(CC) $(CFLAGS) $(BONUS_SRCS) -Lmlx_linux -lmlx_Linux -L /usr/include/minilibx-linux -Imlx_linux -lXext -lX11  -lz -o $(BONUS_NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all clean fclean re bonus
