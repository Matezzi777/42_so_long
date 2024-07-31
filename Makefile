NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = test.c
OBJ = $(SRC:.c=.o)

LIBFT = ./my_libs/libft/libft.a
FT_PRINTF = ./my_libs/ft_printf/libftprintf.a

COL_GREEN = \e[1;32m
COL_GREY = \e[1;30m
COL_BLUE = \e[1;34m
COL_END = \e[0m

all: libft ft_printf $(NAME)

libft:
	@echo "$(COL_BLUE)Building $@$(COL_END)"
	@cd my_libs/libft && make > /dev/null

ft_printf:
	@echo "$(COL_BLUE)Building $@$(COL_END)"
	@cd my_libs/ft_printf && make > /dev/null

$(NAME): $(OBJ)
	@echo "$(COL_BLUE)Building $(NAME)$(COL_END)"
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(COL_GREEN)so_long ready !$(COL_END)"

$(OBJ) : $(SRC)
	@echo "$(COL_BLUE)Creating .o files$(COL_END)"
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

fclean: clean
	@echo "$(COL_GREY)Removing $(NAME)$(COL_END)"
	$(RM) $(NAME)
	@echo "$(COL_GREY)Removing libft$(COL_END)"
	@cd my_libs/libft && make fclean > /dev/null
	@echo "$(COL_GREY)Removing ft_printf$(NAME)$(COL_END)"
	@cd my_libs/ft_printf && make fclean > /dev/null

clean:
	@echo "$(COL_GREY)Removing .o files$(COL_END)"
	$(RM) $(OBJ)

re: fclean all