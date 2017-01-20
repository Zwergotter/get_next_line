/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edeveze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:29:55 by edeveze           #+#    #+#             */
/*   Updated: 2016/11/13 16:26:37 by edeveze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
