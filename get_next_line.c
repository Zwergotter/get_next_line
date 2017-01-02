/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:32:13 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/02 22:59:50 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int find_character(char *str)
{
    int i;

    i = 1;
    while (*str && *str != '\n')
        {
            i++;
            str++;
        }
    if (*str == '\n')
        return (i);
    return (0);
}

void line_read(char **line, char **saved)
{
    int  newline;
    char *temp;

    temp = *saved;
    newline = find_character(temp);
    *line = ft_strsub(temp, 0, newline - 1);
    // *saved = ft_strsub(temp, newline, ft_strlen(temp) - (newline - 1));
    *saved = ft_strdup(temp + newline);
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
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        printf("Test1\n");
        tmp = saved;
        printf("Test2\n");
        saved = ft_strjoin(saved, buf);
        if (saved == NULL)
            return (-1);
        printf("Test\n");
        if (tmp)
            free(tmp);
        if (ft_strchr(saved, '\n'))
            break;
    }
    line_read(line, &saved);
    if (ret == 0 && saved[0] == '\0')
    {
        free(saved);
        return (0);
    }
    return (1);
}
