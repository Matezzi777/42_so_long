#################### VARIABLES ####################
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -I./includes
LIBRARIES = -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
RM = rm -rdf
NAME = so_long

###################### FILES ######################
RAW_SRCS = main.c \
			my_pixel_put.c \
			new_image.c \
			create_trgb.c \
			get_t.c \
			get_r.c \
			get_g.c \
			get_b.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

###################### RULES ######################
all: $(NAME)

$(NAME): mk_libft mk_mlx $(OBJS)
	$(CC) $(OBJS) $(LIBRARIES) $(INCLUDES) -o $@

mk_libft:
	cd libft && make

mk_mlx:
	cd mlx_linux && make

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean: rm_libft rm_mlx
	$(RM) $(OBJS)

rm_libft:
	cd libft && make fclean

rm_mlx:
	cd mlx_linux && make clean

re: fclean all

.PHONY: all mk_libft mk_mlx fclean clean rm_libft rm_mlx re