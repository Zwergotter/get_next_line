/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:32:13 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/20 18:50:14 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Searches newline in string passed as argument. Returns its position or 0.
*/

int		find_character(char *str)
{
	int	i;

	i = 0;
	while (*str && *str != '\n')
	{
		i++;
		str++;
	}
	if (*str == '\n')
		return (i);
	return (0);
}

/*
** Has as arguments buf, where we stored what was read, ret and saved.
** First it puts an '\0' at the buffer's end.
** Then it stores what there is in saved in a temporary string. Like this
** we can create fro saved a string with strjoin that contains saved with buf.
** And we free tmp if there's anything inside of it.
*/

void	fill_saved(char *buf, int ret, char **saved)
{
	char		*tmp;

	buf[ret] = '\0';
	tmp = *saved;
	if (tmp)
	{
		*saved = ft_strjoin(*saved, buf);
		free(tmp);
	}
	else
		*saved = ft_strdup(buf);
}

/*
** It stores a read line from saved in line.
** Creates a int newline and a char *temp.
** temp stores what there's in saved.
** newline calls find_character to know where in temp there is nl.
** If newline = 1, nl is at the beginning. So line is created with strnew(0).
** Else, line is created with strsub, thanks to temp. It starts at the beginning
** and copies it before newline's position.
** saved is created thanks to a strdup after newline's position.
** Finally temp is freed.
*/

void	line_read(char **line, char **saved)
{
	int		newline;
	char	*temp;

	temp = *saved;
	newline = find_character(temp) + 1;
	if (newline == 1)
		*line = ft_strnew(0);
	else
		*line = ft_strsub(temp, 0, newline - 1);
	*saved = ft_strdup(temp + newline);
	free(temp);
}

/*
** Receives 2 arguments, a file descriptor and the line where to store.
** It returns -1, 0 or 1, depending on whether an error happened, the file's
** reading has been completed or a line has been read.
** First it checks if the file does exist and buff_size is a positive value.
** Then it reads it in a loop and calls fill_saved to store in a static *char.
** If saved contains nothing or if a newline is found in saved, we break.
** It checks if ret is negative or nothing is contained in saved.
** It also checks if reading is done and if no newline had been found in saved.
*/

int		get_next_line(const int fd, char **line)
{
	static char	*saved = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		fill_saved(buf, ret, &saved);
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
