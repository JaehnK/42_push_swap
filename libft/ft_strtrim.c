/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:41:19 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/12 13:37:21 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	search_set(char c, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*get_strtrim(char *dest, char *start, char *end)
{
	size_t	i;

	i = 0;
	while (start != end)
	{
		dest[i++] = *start;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	while (search_set(*s1, set))
		s1++;
	start = (char *) s1;
	while (*s1)
		s1++;
	while (search_set(*s1, set) || *s1 == '\0')
		s1--;
	end = (char *) s1 + 1;
	if (end <= start)
		return (dest = ft_strdup(""));
	dest = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	return (get_strtrim(dest, start, end));
}
