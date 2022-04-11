/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/11 10:29:25 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"



void    free_all_map(char **str, t_args *d)
{
    unsigned int    i;
    i = 0;
    while (i < d->nbr_line)
    {
        free(str[i]);
        i++;
    }
    free(str);
}


int	key_hook(int keycode, t_args *d, void *mlx_ptr, void *mlx_win, t_sprite *spr)
{
	int i;

	i = 0;
	//d->map[0][0] = 'P';
	//printf("%d\n", keycode);
	if (keycode == 13 && d->map[d->player_pos->y - 1][d->player_pos->x] && d->map[d->player_pos->y - 1][d->player_pos->x] != '1')
	{
		//printf("%d : %d\n", d->player_pos->x , d->player_pos->y);
		d->map[d->player_pos->y][d->player_pos->x] = '0';
		d->map[d->player_pos->y - 1][d->player_pos->x] = 'P';
	}
	if (keycode == 0 && d->map[d->player_pos->y][d->player_pos->x - 1] && d->map[d->player_pos->y][d->player_pos->x - 1] != '1')
	{
		//printf("%d : %d\n", d->player_pos->x , d->player_pos->y);
		d->map[d->player_pos->y][d->player_pos->x] = '0';
		d->map[d->player_pos->y][d->player_pos->x - 1] = 'P';
	}
	if (keycode == 1 && d->map[d->player_pos->y + 1][d->player_pos->x] && d->map[d->player_pos->y + 1][d->player_pos->x] != '1')
	{
		//printf("%d : %d\n", d->player_pos->x , d->player_pos->y);
		d->map[d->player_pos->y][d->player_pos->x] = '0';
		d->map[d->player_pos->y + 1][d->player_pos->x] = 'P';
	}
	if (keycode == 2 && d->map[d->player_pos->y][d->player_pos->x + 1] && d->map[d->player_pos->y][d->player_pos->x + 1] != '1')
	{
		//printf("%d : %d\n", d->player_pos->x , d->player_pos->y);
		d->map[d->player_pos->y][d->player_pos->x] = '0';
		d->map[d->player_pos->y][d->player_pos->x + 1] = 'P';
	}
    // while (i < d->nbr_line)
    // {
    //     dprintf(1, "valeur de map de : %d || %s", i , d->map[i]);
    //     i++;
    // }
	// dprintf(1, "\n");
	return (0);
}

int	ft_render_frame(t_args *dim)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < (int)dim->nbr_line)
	{
		while (j < dim->line_lenght)
		{
			if (dim->map[i][j] == 'P')
			{
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->hero, x, y);
				dim->player_pos->x = j;
				dim->player_pos->y = i;
			}
			if (dim->map[i][j] == '1')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->tree, x, y);
			if (dim->map[i][j] == '0')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->grass, x, y);
			if (dim->map[i][j] == 'C')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->burger, x, y);
			if (dim->map[i][j] == 'E')
				mlx_put_image_to_window (dim->mlx_ptr, dim->mlx_win, dim->spr->fridge, x, y);
			
			j++;
			x += 32;
		}
		j = 0;
		i++;
		x = 0;
		y += 32;
	}
	return (0);
}

int	main(void)
{
    t_args    dim;
	t_sprite	spr;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*image;
	int		w;
	int		h;

    dim.nbr_line = 0;
    dim.line_lenght = 0;
    dim.fd = open("srcs/test.ber" , O_RDWR);
    //map_dimension(&dim);
    ft_get_map(&dim);
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
	mlx_loop_hook(mlx_ptr, ft_render_frame, &dim);
	mlx_key_hook(mlx_win, key_hook, &dim);
	mlx_clear_window(mlx_ptr, mlx_win);
	//image = mlx_new_image(mlx_ptr, 250, 250);
	mlx_loop(mlx_ptr);
	
    //printf("%s\n", dim.parsing_map);
    //printf ("longeur des lignes : %d\n", dim.line_lenght);
    //printf("Nombre de lignes : %d\n", dim.nbr_line);
	/*i = 0;
    while (i < dim.nbr_line)
    {
        dprintf(1, "valeur de map de : %d || %s", i , dim.map[i]);
        i++;
    }*/
    free_all_map(dim.map, &dim);
    free(dim.parsing_map);
	return (1);
}