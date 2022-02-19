NAME	:=	FDF

CC	:= gcc
CFLAGS	:=	-Wall -Wextra -Werror
MINILIBX_FLAGS	:=	-framework OpenGL -framework AppKit

DIR_SRCS	:=	srcs
DIR_OBJS	:=	.objs
DIR_INCS	:=	incs
DIR_LIBFT	:=	libft
DIR_MINILIBX	:=	minilibx_macos

LST_SRCS	:=	fdf.c	\

LST_OBJS	:=	$(LST_SRCS:.c=.o)

LST_INCS	:=	fdf.h	\

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT	:=	$(DIR_LIBFT)/libft.a
AR_MINILIBX	:=	$(DIR_MINILIBX)/libmlx.a

all: $(NAME)	

$(NAME): $(AR_LIBFT) $(AR_MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) $^ -o $@

 $(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c	$(INCS)	Makefile	|	$(DIR_OBJS)
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

.PHONY:    all bonus clean fclean re
