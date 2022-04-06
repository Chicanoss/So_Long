/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:17:34 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/06 14:23:44 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

void	map_dimension(t_args *d)
{
    int      i;

	i = 0;
    d->nbr_line = 1;
	while (d->parsing_map[i])
	{
		if(d->parsing_map[i] == '\n')
			d->nbr_line++;
		i++;
	}
}