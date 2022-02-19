/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:59:15 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/19 15:11:41 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../incs/fdf.h"

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int schar);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *s1, char c);

#endif