#!/bin/bash
gcc -g -Wall -Wextra -Werror get_next_line.c get_next_line.h test_main.c ./Libft/ft_strsub.c ./Libft/ft_strlen.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c ./Libft/ft_memset.c ./Libft/ft_strdel.c ./Libft/ft_strdup.c  ./Libft/ft_memalloc.c ./Libft/ft_strcat.c ./Libft/ft_strchr.c ./Libft/ft_strcpy.c ./Libft/ft_strjoin.c -I ./Libft
