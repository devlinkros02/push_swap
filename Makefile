NAME    := push_swap
CC		:= gcc
CFLAGS = -Wunreachable-code -Wall -Wextra -Werror -g
LIBFT := ./Libft

HEADERS := -I./include -I$(LIBFT)/include
LIBS    := $(LIBFT)/libft.a
SRCS    := $(shell find ./src -iname "*.c")
OBJS    := ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libft