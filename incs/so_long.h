/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:32:00 by rgeral            #+#    #+#             */
/*   Updated: 2022/04/05 13:45:43 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

char *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int schar);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *s1, char c);

# endif