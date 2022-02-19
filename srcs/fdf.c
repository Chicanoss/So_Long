/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/19 20:12:31 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/fdf.h"

int	draw_line (void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
   		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
    	pixelX += deltaX;
    	pixelY += deltaY;
    	--pixels;
	}
	return(1);
}

int	main(void)
{
	void *id;
	void *win;
	int color;

	color = 253;
	id = mlx_init();
	win = mlx_new_window(id, 300, 300, "Hello");
	if (!id)
		printf("noob\n");
	color = 0;
	//mlx_pixel_put (id, win, 10, 10, color);
	//draw_line(id, win, 0, 0, 300, 300, 0xFFFFFF);
	//draw_line(id, win, 300, 0, 0, 300, 0xFFFFFF);

	int fd;
	char *rslt = NULL;
	char	**splited;
	int i;
	int x;
	int	y;
	int	j;
	int	space;

	i = 0;
	x = 1;
	y = 1;
	j = 0;
	space = 10;
	fd = open("srcs/10-2.fdf" , O_RDWR);
	while(i < 10)
	{
		rslt = get_next_line(fd);
		//printf("test");
		splited = ft_split(rslt, ' ');
		while(splited[j])
		{
			//printf("test");
			printf("coord : [%d,%d]\n valeur : %s", x, y, splited[j]);
			mlx_pixel_put (id, win, x, y, 0xFFFFFF);
			x += space * 2 + 1;
			j++;
		}
		x = 0;
		y += space + 1;
		j = 0;
		i++;
	}

	//printf("%s\n", rslt);
	//printf("%s\n", rslt);
	mlx_loop(id);
	return(1);
}