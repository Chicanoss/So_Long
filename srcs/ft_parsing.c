/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeral <rgeral@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:48:10 by rgeral            #+#    #+#             */
/*   Updated: 2022/02/21 19:37:24 by rgeral           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"


char    *strnjoin(char *s1, char *s2, int stop)
{
    int     i;
    int     j;
    char    *join;

    i = 0;
    j = 0;
    join = malloc ((sizeof(s1) * ft_strlen(s1)) + (sizeof(*s2) * stop)  + 1);
    if (!join)
    {
        free(s1);
        return (0);
    }
    while (s1[i])
    {
        join[i] = s1[i];
        i++;
    }
    while (j < stop)
    {
        join[i + j] = s2[j];
        j++;
    }
    join[i + j] = '\0';
    return (join);
}

int ft_check_length(char   *values) // Compare le nombre d'espace de la première ligne avec toutes les autres.
{
    int i;
    int j;
    int line_size;

    i = 0;
    j = 0;
    line_size = 0;
    while (values[i])
    {
        if (values[i] == ' ')
            line_size++;
        if (values[i] == '\n')
            break;
        i++;
    }
    i = 0;
    while (values[i])
    {
        if (values[i] == ' ')
            j++;
        if (values[i] == '\n')
        {
            if(j != line_size)
                return(0);
            else
                j = 0;
        }
        i++;
    }
    return(1);
}
int ft_check_doubles(char   *values) //Check si un espace n'est pas suivi par un espace et que seul les char autorisé sont utilisés.
{
    int i;

    i = 0;
    while (values[i])
    {
        if (values[i] == ' ' && values[i + 1] == ' ')
            return(0);
        if (ft_isdigit(values[i]) != 1 && values[i] != '-' && values[i] != ' ' && values[i] != '\n')
            return(0);
        i++;
    }
    return(1);
}
int ft_parsing(int fd) //Check hub du parsing, c'est ici k'sas'pace poto.
{
    int     ret;
    char    buf[42];
    char    *values;

    values = malloc(1);
    if (!values)
        return (0);
    *values = '\0';
    ret = 1;
    while (ret)
    {
        ret = read(fd, buf, 42);
        values = strnjoin(values, buf, ret);
    }
    if(ft_check_length(values) == 0)
        return(0);
    if(ft_check_doubles(values) == 0)
        return(0);
    printf("%s\n", values);
    return(1);
}
