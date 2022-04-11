/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:32:00 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/11 14:07:35 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_argument 
{
    int 	nbr_line;
	int		line_lenght;
	char	*parsing_map;
	char	*BUFFER[42];
	int		fd;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		count_burger;
	int		count_exit;
	struct	s_sprite	*spr;
	struct	s_player_pos *player_pos;

}	t_args;

typedef struct s_player_pos
{
	int	x;
	int	y;
}				t_player_pos;

typedef struct s_sprite
{
	void	*hero;
	void	*tree;
	void	*grass;
	void	*burger;
	void	*fridge;
} t_sprite;

typedef struct s_gnl
{
    char    buffer[BUFFER_SIZE];
    int     bufpos;
    int     buflen;
}   t_gnl;


char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int schar);
char	*ft_strjoin_2(char *s1, char *s2);
char	*ft_strndup(char *s1, char c);
void	map_dimension(t_args *d);
char    *ft_strnjoin(char *s1, char *s2, int len);
char	*mod_strnjoin(char *s1, char *s2, int n);
void	ft_parsing(t_args *d);
void    get_lines(t_args *d);
void	ft_get_map(t_args *dim);
void    free_all(char **str);
void    borders_parsing(t_args *d);
int		 hero_move(int	keycode, t_args *d);

# endif