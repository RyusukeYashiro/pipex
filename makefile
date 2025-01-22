NAME = pipex

CC = cc

SRCS = src/main.c \
		src/utils/check.c \
		src/utils/child.c \
		src/utils/errorDeal.c \
		src/utils/exec.c \
		src/utils/file_open.c \
		src/utils/ft_free_split.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./include -I./libft/include

CFLAGS = -Wall -Wextra -Werror -g -O0 $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

LIBFT_PATH = ./libft
LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) $(OBJS) $(LIBFT_PATH)/$(LIBFT_NAME) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re