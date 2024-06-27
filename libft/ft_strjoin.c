/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:26:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/11 22:58:32 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;	
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2);
	dest = (char *) malloc(sizeof(char) * (len_s1 + len_s2));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, len_s1);
	ft_strlcat(dest, s2, len_s1 + len_s2);
	return (dest);
}
