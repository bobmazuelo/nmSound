/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazuelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:51:14 by mmazuelo          #+#    #+#             */
/*   Updated: 2022/02/18 17:50:58 by mmazuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_token_count(const char *str, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (*str)
	{
		if (*str != c && cont == 0)
		{
			cont = 1;
			i++;
		}
		else if (*str == c)
			cont = 0;
		str++;
	}
	return (i);
}

static size_t	ft_strclen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	pos;
	size_t	toklen;
	char	**ptr;

	pos = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char **) * (ft_token_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			toklen = ft_strclen(s, c);
			ptr[pos] = (char *)ft_calloc(toklen + 1, sizeof(char));
			ft_memcpy(ptr[pos], s, toklen);
			s += toklen;
			pos++;
		}
	}
	ptr[pos] = NULL;
	return (ptr);
}

/*
int main() {
  char *s = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit";
  char  **splits = ft_split(s, 's');
  for (int i = 0; splits[i] != NULL; i++)
    printf("%s\n", splits[i]);
  free(splits);
  return 0;
}
*/
