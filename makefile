NAME = FDF

#NAME_BONUS = pipex_bonus

SRCS =	SRCS/fdf.c \

LIB = minilibx_macos/libmlx.a \

#SRCS_BONUS =	SRCS_bonus/pipex_bonus.c \
				SRCS_bonus/pipex_utils_bonus.c \
				SRCS_bonus/pipex_conditions_bonus.c \
				SRCS_bonus/ft_split_bonus.c

OBJS = $(SRCS:.c=.o)

#OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = incs/fdf.h

#HEADER_BONUS = incs_bonus/pipex_bonus.h

CC = gcc

FLAGS = -Wall -Werror -Wextra

FLAGS2 = -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FLAGS2) $(LIB) $(OBJS) -o $(NAME)

#bonus: $(NAME_BONUS)

#$(NAME_BONUS): $(OBJS_BONUS) $(HEADER_BONUS) Makefile
#	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
 
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

#re_bonus: fclean bonus

.PHONY:	all bonus clean fclean re