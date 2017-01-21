#!/bin/bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line.h test_main.c ./libft/ft_strsub.c ./libft/ft_strlen.c ./libft/ft_strnew.c ./libft/ft_bzero.c ./libft/ft_memset.c ./libft/ft_strdel.c ./libft/ft_strdup.c  ./libft/ft_memalloc.c ./libft/ft_strcat.c ./libft/ft_strchr.c ./libft/ft_strcpy.c ./libft/ft_strjoin.c -I ./libft/includes
