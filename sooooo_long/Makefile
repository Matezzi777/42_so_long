#################### VARIABLES ####################
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -I./includes
LIBRARIES = -L./libft -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
RM = rm -rdf
NAME = so_long

###################### FILES ######################
RAW_SRCS = main.c \
			check_arguments.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

###################### RULES ######################
all: $(NAME)

$(NAME): mk_libft mk_mlx $(OBJS)
	$(CC) $(OBJS) $(LIBRARIES) $(INCLUDES) -o $@

mk_libft:
	cd libft && make bonus

mk_mlx:
	cd mlx && make

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean: rm_libft rm_mlx
	$(RM) $(OBJS)

rm_libft:
	cd libft && make fclean

rm_mlx:
	cd mlx && make clean

re: fclean all

.PHONY: all mk_libft mk_mlx fclean clean rm_libft rm_mlx re