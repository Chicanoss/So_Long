/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/19 18:23:52 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"



void    free_all_map(char **str, t_args *d)
{
    unsigned int    i;
    i = 0;
    while ((int)i < d->nbr_line)
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int	ft_render_frame(t_args *dim)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int)dim->nbr_line * 32)
	{
		while (x < dim->line_lenght * 32)
		{
			if (dim->map[y / 32][x / 32] == 'P')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->hero, x, y);
			else if (dim->map[y / 32][x / 32] == '1')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->tree, x, y);
			else if (dim->map[y / 32][x / 32] == '0')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->grass, x, y);
			else if (dim->map[y / 32][x / 32] == 'C')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->burger, x, y);
			else if (dim->map[y / 32][x / 32] == 'E')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->fridge, x, y);
			x += 32;
		}
		x = 0;
		y += 32;
	}
	return (0);
}
int	map_in_game(t_args *dim)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (int)dim->nbr_line * 32)
	{
		while (x < dim->line_lenght * 32)
		{
			if (dim->map[y / 32][x / 32] == 'P')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->hero, x, y);
			x+= 32;
		}
		x = 0;
		y += 32;
	}
	return(0);
}

int	main(int argc, char	**argv)
{
	t_args    	dim;
	t_sprite	spr;
	void		*mlx_ptr;
	void		*mlx_win;
	int			w;
	int			h;
	int			i;

	dim.count_burger = 0;
	dim.count_exit = 0;
	dim.count_char = 0;
	if (argc != 2)
	{
		perror("Put only the map's path as ARG");
		exit(EXIT_FAILURE);
	}
 	dim.fd = open(argv[1] , O_RDWR);
	if (dim.fd == -1)
	{
		perror("cannot open file");
		exit(EXIT_FAILURE);
	}
    dim.nbr_line = 0;
    dim.line_lenght = 0;
    ft_get_map(&dim, argv);
	ft_parsing(&dim);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, dim.line_lenght * 32, dim.nbr_line * 32, "./so_long");
	dim.mlx_ptr = mlx_ptr;
	dim.mlx_win = mlx_win;
	dim.spr = &spr;
	spr.hero = mlx_xpm_file_to_image(mlx_ptr, "images/hero.xpm", &w, &h);
	spr.tree = mlx_xpm_file_to_image(mlx_ptr, "images/bush.xpm", &w, &h);
	spr.grass = mlx_xpm_file_to_image(mlx_ptr, "images/grass.xpm", &w, &h);
	spr.burger = mlx_xpm_file_to_image(mlx_ptr, "images/burger.xpm", &w, &h);
	spr.fridge = mlx_xpm_file_to_image(mlx_ptr, "images/fridge.xpm", &w, &h);
	ft_render_frame(&dim);
	mlx_loop_hook(mlx_ptr, map_in_game, &dim);
	mlx_key_hook(dim.mlx_win, hero_move, &dim);
	mlx_loop(mlx_ptr);
	
    //printf("%s\n", dim.parsing_map);
    //printf ("longeur des lignes : %d\n", dim.line_lenght);
    //printf("Nombre de lignes : %d\n", dim.nbr_line);
	i = 0;
    while (i < dim.nbr_line)
    {
        dprintf(1, "valeur de map de : %d || %s", i , dim.map[i]);
        i++;
    }
    free_all_map(dim.map, &dim);
    free(dim.parsing_map);
	return (0);
}