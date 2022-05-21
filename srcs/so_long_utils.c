/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:25:38 by rgeral            #+#    #+#             */
/*   Updated: 2022/05/21 13:48:24 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../incs/so_long.h"

char	*mod_strnjoin(char *s1, char *s2, int n)
{
	size_t	i;
	size_t	j;
	char	*str;
	int		k;

	k = 0;
	j = ft_strlen(s1) + ft_strlen(s2) - (ft_strlen(s2) - n);
	str = (char *)malloc(sizeof(char) * (j + 2));
	i = -1;
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while (i <= j && s2[k])
	{
		str[i++] = s2[k++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_exit(t_args *d)
{
	free_all_map(d->map, d);
	free(d->parsing_map);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(const char	*first, const char	*second)
{
	size_t	i;

	i = 0;
	while (first[i] && (unsigned char)first[i] == \
	(unsigned char)second[i])
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

void	print_move(t_args *d)
{
	d->actions++;
	ft_putnbr_fd(d->actions, 1);
	write(1, "\n", 1);
}
