/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:58:40 by edeveze           #+#    #+#             */
/*   Updated: 2017/01/02 17:31:51 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line))
            {
                write(1, "Affichage\n",10);
                printf("%s\n", line);
                printf("Non affichage\n");
                free(line);
            }
        close(fd);
    }
    return (0);
}
