/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:54:17 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/05 14:24:43 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*dest;

	idx = 0;
	dest = (unsigned char *) s;
	while (idx < n)
	{
		dest[idx++] = c;
	}
	return (dest);
}
