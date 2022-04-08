/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:56:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/08 18:40:59 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"
/*
	Ne gère pas encore la dernière ligne ??..
*/
void	check_borders(t_args *d)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	while (j < d->line_lenght - 1)
	{
		if (d->map[0][j] != '1')
		{
			dprintf(1, "valeur de map[%d][%d] est : %d\n", i , j , d->map[i][j]);
			dprintf(1, "no borders top\n");
		}
		j++;
	}
	j = 0;
	while (d->map[i])
	{
			while (d->map[i][j])
			{
				if (d->map[i][0] != '1' || d->map[i][d->line_lenght - 1] != '1')
				{
					dprintf(1, "no borders mid\n");
					dprintf(1, "valeur de map[%d][%d] est : %d\n", i , j , d->map[i][j]);
				}
				j++;
			}
			j = 0;
			i++;
	}
}

	
	
	
	
	
	
	
	
	/*while (d->map[i])
	{
		while (d->map[i][j])
		{
			while (d->map[0][j])
			{
				if (i > 0)
					break;
				if (d->map[i][j] != '1')
					dprintf(1, "no borders top\n");
				j++;
			}
		//	if (d->map[i][0] != '1' && d->map[i][d->line_lenght])
				//dprintf(1, "no borders mid\n");
			//if (d->map[d->nbr_line][0] != '1' && d->map[d->nbr_line][d->line_lenght] != '1')
				//dprintf(1, "no borders bot");
		}
		j = 0;
		i++;
	}
}*/

void	ft_parsing(t_args *d)
{
	check_borders(d);
	dprintf(1 , "parsing 2 Ok\n");
}