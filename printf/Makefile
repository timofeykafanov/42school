NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = include
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, ft_printf.c ft_itoa.c utils.c handle_c_s_d_i_u.c handle_p_x_percent.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
