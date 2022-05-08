/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:06:33 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/18 18:13:15 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	if (!s && !c && !n)
		return (NULL);
	i = 0;
	str = s;
	while (i < n)
	{
		if (*(unsigned char *)(str) == (unsigned char)c)
			return ((void *)(str));
		str++;
		i++;
	}
	return (0);
}
