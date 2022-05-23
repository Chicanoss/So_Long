/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:09:18 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/23 17:46:00 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	exit_up(t_args *d)
{
	if (d->map[d->y - 1][d->x] == 'E' &&
	d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->y - 1][d->x] == 'E' &&
	d->count_burger != 0)
		return (0);
	else
	{
		go_up(d);
		d->actions++;
	}
	return (0);
}

int	exit_down(t_args *d)
{
	if (d->map[d->y + 1][d->x] == 'E' &&
	d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->y + 1][d->x] == 'E' &&
	d->count_burger != 0)
		return (0);
	else
	{
		go_down(d);
		d->actions++;
	}
	return (0);
}

int	exit_right(t_args *d)
{
	if (d->map[d->y][d->x + 1] == 'E' &&
	d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->y][d->x + 1] == 'E' &&
	d->count_burger != 0)
		return (0);
	else
	{
		go_right(d);
		d->actions++;
	}
	return (0);
}

int	exit_left(t_args *d)
{
	if (d->map[d->y][d->x - 1] == 'E' &&
	d->count_burger == 0)
		exit(EXIT_SUCCESS);
	else if (d->map[d->y][d->x - 1] == 'E' &&
	d->count_burger != 0)
		return (0);
	else
	{
		go_left(d);
		d->actions++;
	}
	return (0);
}
