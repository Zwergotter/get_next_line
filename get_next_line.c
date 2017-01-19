/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:32:13 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/19 16:08:43 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_character(char *str)
{
	int	i;

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

void	fill_it(char *buf, int ret, char **saved)
{
	char		*tmp;

	buf[ret] = '\0';
	tmp = *saved;
	*saved = ft_strjoin(*saved, buf);
	if (tmp)
		free(tmp);
}

void	line_read(char **line, char **saved)
{
	int		newline;
	char	*temp;

	temp = *saved;
	newline = find_character(temp);
	if (newline == 1 || newline == 0)
		*line = ft_strnew(0);
	else
		*line = ft_strsub(temp, 0, newline - 1);
	*saved = ft_strdup(temp + newline);
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*saved = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		fill_it(buf, ret, &saved);
		if ((saved == NULL) || ft_strchr(saved, '\n'))
			break ;
	}
	if (ret < 0 || saved == NULL)
		return (-1);
	if (ret < 1 && !ft_strchr(saved, '\n'))
	{
		*line = saved;
		if (saved == NULL || saved[0] == '\0')
			return (0);
		saved = NULL;
		return (1);
	}
	line_read(line, &saved);
	return (1);
}
