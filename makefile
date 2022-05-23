NAME	:=	so_long

CC	:= gcc
CFLAGS	:=	-Wall -Wextra -Werror
MINILIBX_FLAGS	:=	-framework OpenGL -framework AppKit

DIR_SRCS	:=	srcs
DIR_OBJS	:=	objs
DIR_INCS	:=	incs
DIR_LIBFT	:=	libft
DIR_MINILIBX	:=	mlx

LST_SRCS	:=	so_long.c	\
				get_next_line.c \
				get_map.c \
				parsing.c \
				borders_parsing.c \
				so_long_utils.c \
				hero_move.c \
				exit_condition.c \
				draw_on_map.c \
				
LST_OBJS	:=	$(LST_SRCS:.c=.o)

LST_INCS	:=	so_long.h	

SRCS	:=	$(addprefix $(DIR_SRCS)/,$(LST_SRCS))
OBJS	:=	$(addprefix $(DIR_OBJS)/,$(LST_OBJS))
INCS	:=	$(addprefix $(DIR_INCS)/,$(LST_INCS))

AR_LIBFT	:=	$(DIR_LIBFT)/libft.a
AR_MINILIBX	:=	$(DIR_MINILIBX)/libmlx.a

all: $(NAME)

$(NAME): $(AR_LIBFT) $(AR_MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) -o $@ $(OBJS) $(AR_MINILIBX) $(AR_LIBFT)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c Makefile $(INCS)
	mkdir -p $(DIR_OBJS)
	$(CC) $(CFLAGS) -I $(DIR_INCS) -c $< -o $@

$(AR_LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(AR_MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

compile:
	@$(MAKE) -C mlx
	@echo " [ OK ] | Minilibx ready!"
	@$(MAKE) -C libft
	@echo " [ OK ] | Libft ready!"

clean:
	rm -rf $(DIR_OBJS)
	@$(MAKE) clean -C libft
	@echo "object files removed"

fclean: clean
	@$(MAKE) clean -C mlx
	@$(MAKE) fclean -C libft
	rm -rf $(NAME)
	@echo "fclean : done !"

re: fclean all

.PHONY:    all clean fclean re
