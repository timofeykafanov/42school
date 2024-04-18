NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
INCLUDE = include
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, ft_printf.c ft_itoa_u.c)
OBJS = $(SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJS)
	ar rcs $@ $(OBJS) $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(LIBFT) -I $(INCLUDE) -c $< -o $@ 

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBFT)/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
