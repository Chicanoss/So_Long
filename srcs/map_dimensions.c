/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:17:34 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/05 20:13:01 by rgeral           ###   ########.fr       */
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
   // printf("valeur de i : %d", i);
	// printf("\nnombre de lignes : %d\n" , d->nbr_line);
    //printf("%s", d->parsing_map);
}