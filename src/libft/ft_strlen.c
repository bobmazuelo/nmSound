/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 11:45:58 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/19 00:43:13 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
 * size_t	ft_strlen(const char *str)
 * {
 * 		const char *ptr;
 *
 * 		ptr = str;
 * 		while (*ptr)
 * 			ptr++;
 * 		return (ptr - str);
 * }
 *
 *  
 * size_t  ft_strlen(const char *str) 
 * {
 * 	if (*str == '\0')
 *		return (0);
 *	else
 *		return (1 + ft_strlen(str + 1));
 *	}
 *
 */
