NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCDIR	= ./src/
BINDIR	= ./bin/
PATH_LIBMLX	= ../mlx_linux
PATH_LIBFT	= ../lib_libft
PATH_PRINTF	= ../lib_printf
PATH_GNL	= ../get_next_line
LIBMLX		= libmlx_Linux.a
LIBFT		= libft.a
FT_PRINTF	= libftprintf.a


HEADERS		= -I ./include -I $(PATH_LIBMLX) -I $(PATH_LIBFT) -I $(PATH_PRINTF) -I $(PATH_GNL)
LIBS 		= $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) $(PATH_LIBMLX)/$(LIBMLX)
SRCS		= test.c
OBJS		= $(addprefix $(BINDIR), $(SRCS:.c=.o))

all: mk_mlx mk_libft mk_printf mk_gnl $(NAME)

mk_mlx: 
	cd $(PATH_LIBMLX) && make > /dev/null

mk_libft:
	cd $(PATH_LIBFT) && make > /dev/null

mk_printf:
	cd $(PATH_PRINTF) && make > /dev/null

mk_gnl:
	cd $(PATH_GNL) && $(CC) $(CFLAGS) -c get_next_line.c -o get_next_line.o && $(CC) $(CFLAGS) -c get_next_line_utils.c -o get_next_line_utils.o

