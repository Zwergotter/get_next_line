/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:32:13 by edeveze           #+#    #+#             */
/*   Updated: 2016/12/18 23:59:27 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int find_character(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        return (i);
    return (0);
}

void line_read(char **line, char *saved)
{
    int  newline;
    char *temp;

    temp = saved;
    newline = find_character(saved);
    *line = ft_strsub(saved, 0, newline);
    saved = ft_strsub(saved, newline + 1, ft_strlen(saved) - newline);
    free(temp);
}

int get_next_line(const int fd, char **line)
{
    static char *saved = NULL;
    char buf[BUFF_SIZE];
    char *tmp;
    int ret;

    if (fd < 0)
        return (-1);
    while ((ret = read(fd, buf, BUFF_SIZE)) && ((ft_strchr(saved, '\n') == NULL)))
    {
        buf[ret] = '\0';
        tmp = saved;
        saved = ft_memalloc(ft_strlen(saved) + ft_strlen(buf));
        *saved = 0;
        saved = ft_strcpy(saved, tmp);
        saved = ft_strcat(saved, buf);
        if (tmp)
            free(tmp);
    }
    line_read(line, saved);
    if (ret == 0 && saved[0] == '\0')
    {
        free(saved);
        return (0);
    }
    printf("Test\n");
    return (1);
}
