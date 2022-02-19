/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:19:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/19 22:49:49 by rgeral           ###   ########.fr       */
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

int	**make_map(fd)
{
	int		i;
	int		j;
	char	**splited;
	char	*temp;
	int		**map;
	
	i = 0;
	j = 0;
	while(i < 9)
	{
		temp = get_next_line(fd);
		splited = ft_split(temp , ' ');
		map = put_in_map(splited);
	}
	return (map);
}

int	**put_in_map(char	**splited)
{
	int	**map;
	int i;

	

}

int	main(void)
{
	int	**map;
	int	fd;
	int i;

	/*parsing 
	if (!checkmap)
		return (error);
	*/
	fd = open("srcs/10-2.fdf" , O_RDWR);
	map = make_map(fd);
	i = 0;
	//while (map)
	//{
		//printf("%d\n" , map[3][1]);
		//i++;
	//}
	
	return (1);
}