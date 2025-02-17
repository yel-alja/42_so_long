NAME = so_long

# BONUS_NAME = checker

# BONUS_SRCS =

SRCS = main.c parsing.c solong_utils.c ft_split.c check_map.c

OBJS:= $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #remove  -g

all:$(NAME)

# bonus:$(BONUS_NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
BONUS_OBJS:= $(BONUS_SRCS:.c=.o)

# $(BONUS_NAME):$(BONUS_OBJS)
	# $(CC) $(CFLAGS) $(BONUS_SRCS) -o $(BONUS_NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
