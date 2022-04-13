/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:09:18 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/13 18:22:01 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	exit_up(t_args *d)
{
	if (d->map[d->player_pos->y - 1][d->player_pos->x] == 'E' && d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->player_pos->y - 1][d->player_pos->x] == 'E' && d->count_burger != 0)
		return(0);
	else 
		go_up(d);
	return(0);
}

int	exit_down(t_args *d)
{
	if (d->map[d->player_pos->y + 1][d->player_pos->x] == 'E' && d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->player_pos->y + 1][d->player_pos->x] == 'E' && d->count_burger != 0)
		return(0);
	else 
		go_down(d);
	return(0);
}

int	exit_right(t_args *d)
{
	if (d->map[d->player_pos->y][d->player_pos->x + 1] == 'E' && d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->player_pos->y][d->player_pos->x + 1] == 'E' && d->count_burger != 0)
		return(0);
	else 
		go_right(d);
	return(0);
}

int	exit_left(t_args *d)
{
	if (d->map[d->player_pos->y][d->player_pos->x - 1] == 'E' && d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->player_pos->y][d->player_pos->x - 1] == 'E' && d->count_burger != 0)
		return(0);
	else 
		go_left(d);
	return(0);
}
