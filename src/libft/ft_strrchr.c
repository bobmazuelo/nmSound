/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:38:39 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/18 18:21:24 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	while (n >= 0)
	{
		if (s[n] == (unsigned char)c)
			return ((char *)(s + n));
		n--;
	}
	return (0);
}
