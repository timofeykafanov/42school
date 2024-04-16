NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
INCLUDE = include
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, ft_printf.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
