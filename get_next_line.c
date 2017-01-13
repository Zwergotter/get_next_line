/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:32:13 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/13 18:20:21 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	//*saved = ft_strsub(temp, newline, ft_strlen(temp) - (newline - 1));
	*saved = ft_strdup(temp + newline);
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	static char	*saved = NULL;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = saved;
		saved = ft_strjoin(saved, buf);
		if (saved == NULL)
			return (-1);
		if (tmp)
			free(tmp);
		/*if (ret < BUFF_SIZE && ft_strchr(saved, '\n') == NULL)
		{
			printf("Start loop - Line value is : %s\n", *line);
			*line = ft_strdup(saved);
			printf("Dup done - Line value is : %s\n", *line);
			free(saved);
			return (0);
		}
		printf("After loop - Line value is : %s\n", *line);*/
		if (ft_strchr(saved, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret < 1 && !ft_strchr(saved, '\n'))
	{
		if (saved != NULL && saved[0] != '\0')
		{
			*line = saved;
			saved = NULL;
			return (1);
		}
		else
		{
			if (saved != NULL)
			{
				free(saved);
				saved = NULL;
			}
			*line = NULL;
			return (0);
		}
	}
	line_read(line, &saved);
	// printf("ret = %d | line = \"%s\" | saved = \"%s\"\n", ret, *line, saved);
	if (ret == 0 && **line == '\0' && *saved == '\0')
	{
		free(saved);
		saved = NULL;
		free(*line);
		*line = NULL;
		return (0);
	}
	return (1);
}
