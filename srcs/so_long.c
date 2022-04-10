/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:39:12 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/10 15:35:27 by rgeral           ###   ########.fr       */
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
	d->map[0][0] = 'P';
    while (i < d->nbr_line)
    {
        dprintf(1, "valeur de map de : %d || %s", i , d->map[i]);
        i++;
    }
	return (0);
}


int	main(void)
{
    t_args    dim;
	t_sprite	spr;
	void	*mlx_ptr;
	void	*mlx_win;
	int		w;
	int		h;
	int		i;
	int		j;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
    dim.nbr_line = 0;
    dim.line_lenght = 0;
    dim.fd = open("srcs/test.ber" , O_RDWR);
    //map_dimension(&dim);
    ft_get_map(&dim);
	ft_parsing(&dim);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, dim.line_lenght * 32, dim.nbr_line * 32, "./so_long");
	spr.hero = mlx_xpm_file_to_image(mlx_ptr, "images/hero.xpm", &w, &h);
	spr.tree = mlx_xpm_file_to_image(mlx_ptr, "images/bush.xpm", &w, &h);
	spr.grass = mlx_xpm_file_to_image(mlx_ptr, "images/grass.xpm", &w, &h);
	spr.burger = mlx_xpm_file_to_image(mlx_ptr, "images/burger.xpm", &w, &h);
	spr.fridge = mlx_xpm_file_to_image(mlx_ptr, "images/fridge.xpm", &w, &h);
	while (i < dim.nbr_line)
	{
		while (j < dim.line_lenght)
		{
			if (dim.map[i][j] == 'P')
			{
				mlx_put_image_to_window (mlx_ptr, mlx_win, spr.hero, x, y);
			}
			if (dim.map[i][j] == '1')
				mlx_put_image_to_window (mlx_ptr, mlx_win, spr.tree, x, y);
			if (dim.map[i][j] == '0')
				mlx_put_image_to_window (mlx_ptr, mlx_win, spr.grass, x, y);
			if (dim.map[i][j] == 'C')
				mlx_put_image_to_window (mlx_ptr, mlx_win, spr.burger, x, y);
			if (dim.map[i][j] == 'E')
				mlx_put_image_to_window (mlx_ptr, mlx_win, spr.fridge, x, y);
			
			j++;
			x += 32;
		}
		j = 0;
		i++;
		x = 0;
		y += 32;
	}
	mlx_key_hook(mlx_win, key_hook, &dim);
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