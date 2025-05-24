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
INCLUDES = -I./include \
          -I./lib/libft/include \
          -I./lib/ft_printf/include

RM      = rm -f
LIBFT   = ./lib/libft/libft.a
PRINTF  = ./lib/ft_printf/libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(PRINTF) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C lib/libft

$(PRINTF):
	$(MAKE) -C lib/ft_printf

clean:
	$(RM) $(OBJ)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean

re: fclean all