/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:14:04 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/03 19:59:02 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pd;
	const char		*ps;
	char			*ld;
	const char		*ls;

	pd = dst;
	ps = src;
	if (!pd && !ps)
		return (NULL);
	if (pd < ps)
		while (len--)
			*pd++ = *ps++;
	else
	{
		ld = pd + (len - 1);
		ls = ps + (len - 1);
		while (len--)
			*ld-- = *ls--;
	}
	return (dst);
}	
