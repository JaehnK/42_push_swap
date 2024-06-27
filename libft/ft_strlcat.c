/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:56:29 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/11 22:24:14 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{	
	size_t	idx;
	size_t	dstlen;	
	size_t	srclen;

	idx = 0;
	if (!dst && !size)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (srclen + size);
	while ((src[idx] != '\0') && (idx + dstlen < size - 1))
	{
		dst[dstlen + idx] = src[idx];
		idx++;
	}
	dst[dstlen + idx] = '\0';
	return (srclen + dstlen);
}
