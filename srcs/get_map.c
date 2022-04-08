/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:21:19 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/08 11:42:54 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

void    get_map(t_args *d)
{
    int i;

    i = 0;
    d->map = ft_calloc(d->nbr_line + 1, sizeof(char *));
    while (i < d->nbr_line)
    {
        d->map[i] = ft_calloc(d->line_lenght + 1, sizeof(char)); 
        i++;
    }
    i = 0;
    while (i < d->nbr_line)
    {
        d->map[i] = get_next_line(d->fd);
        i++;
    }
    i = 0;
    while (i < d->nbr_line)
    {
        dprintf(1, "valeur de map de : %d || %s", i , d->map[i]);
        i++;
    }
}