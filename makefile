NAME    = pipex

SRC     = src/main.c \
         src/utils/check.c \
         src/utils/child.c \
         src/utils/errordeal.c \
         src/utils/exec.c \
         src/utils/file_open.c \
         src/utils/ft_free_split.c

OBJ     = $(SRC:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
INCLUDES = -I./include -I./libft
RM      = rm -f
LIBFT   = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all