/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:53:52 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/18 19:58:19 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../incs/so_long.h"

char	*ft_strcpy(char *s1, char *s2, char *str, unsigned int len)
{
	unsigned int		j;
	unsigned int		i;

	j = 0;
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int len)
{
	int		i;
	int		j;
	char	*str;

	if (s1)
		i = ft_strlen((char *)s1);
	else
		i = 0;
	j = len;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
	{
		if (s1)
			free(s1);
		perror("Error");
		exit(0);
	}
	str = ft_strcpy(s1, s2, str, len);
	free(s1);
	return (str);
}

int	gnl_read(t_gnl *gnl, int fd)
{
	if (gnl->bufpos >= gnl->buflen)
	{
		gnl->bufpos = 0;
		gnl->buflen = read(fd, gnl->buffer, 1);
	}
	if (gnl->buflen < 0)
		perror("Error");
	return (gnl->buflen);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl = {{}, 0, 0};
	char			*before_buf;
	int				n;
	int				nl;

	before_buf = NULL;
	nl = 0;
	while (!nl)
	{
		n = gnl_read(&gnl, fd);
		if (n < 0)
		{
			if (before_buf)
				free(before_buf);
			exit(0);
		}
		if (n == 0)
			break ;
		n = gnl.bufpos;
		while (!nl && gnl.bufpos < gnl.buflen)
			nl = (gnl.buffer[gnl.bufpos++] == '\n');
		before_buf = ft_strnjoin(before_buf, gnl.buffer + n, gnl.bufpos - n);
	}
	return (before_buf);
}
