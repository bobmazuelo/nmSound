/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:33:08 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/03 20:31:00 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(needle);
	if (!j)
		return ((char *)haystack);
	while (haystack[i] != '\0' && j <= len)
	{
		if (ft_strncmp(&haystack[i], needle, j) == 0)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
