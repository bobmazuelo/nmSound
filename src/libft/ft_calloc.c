/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 09:36:32 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/03 19:14:08 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*call;
	unsigned char	*ptr;
	size_t			n;

	call = malloc(count * size);
	if (!call)
		return (0);
	ptr = call;
	n = (count * size);
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
	return (call);
}
