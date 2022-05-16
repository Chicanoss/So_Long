NAME	:=	so_long

CC	:= gcc
CFLAGS	:=	-Wall -Wextra -fsanitize=address -g3
MINILIBX_FLAGS	:=	-framework OpenGL -framework AppKit

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	incs
DIR_LIBFT	:=	libft
DIR_MINILIBX	:=	minilibx_macos

LST_SRCS	:=	so_long.c	\
				get_next_line.c \
				get_map.c \
				parsing.c \
				borders_parsing.c \
				so_long_utils.c \
				hero_move.c \
				exit_condition.c \
				
LST_OBJS	:=	$(LST_SRCS:.c=.o)

LST_INCS	:=	so_long.h	\

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT	:=	$(DIR_LIBFT)/libft.a
AR_MINILIBX	:=	$(DIR_MINILIBX)/libmlx.a

all: $(NAME)	

$(NAME): $(AR_LIBFT) $(AR_MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) $^ -o $@

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@

$(AR_LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(AR_MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:    all clean fclean re
