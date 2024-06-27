/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:07:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/08 16:38:51 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_gnl_strlen(const char *s, char c)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] != c && s[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_gnl_strjoin(char *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		i_s1;
	int		len1;
	int		len2;

	i = 0;
	i_s1 = 0;
	len1 = ft_gnl_strlen(s1, '\0');
	len2 = ft_gnl_strlen(s2, '\0');
	ans = (char *) ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!ans)
		return (NULL);
	while (s1 && i < len1)
		ans[i++] = s1[i_s1++];
	while (s2 && i < len1 + len2)
		ans[i++] = *s2++;
	ans[i] = '\0';
	free(s1);
	return (ans);
}

char	*ft_gnl_strdup(char *s, int extra_size)
{
	size_t	len;
	size_t	idx;
	char	*res;

	idx = 0;
	len = ft_gnl_strlen(s, '\0');
	res = (char *) ft_calloc(sizeof(char), (len + extra_size + 1));
	if (!res)
		return (NULL);
	while (idx < len)
	{
		res[idx] = s[idx];
		idx++;
	}
	while (idx < len + extra_size)
		res[idx++] = '\0';
	if (s)
		free(s);
	return (res);
}
