/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:14:44 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/16 18:24:59 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_long_count(int n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;

	i = ft_long_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	ptr[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
	}
	while (n / 10)
	{
		ptr[i--] = 0x30 ^ (n % 10);
		n /= 10;
	}
	ptr[i] = 0x30 ^ n;
	return (ptr);
}
