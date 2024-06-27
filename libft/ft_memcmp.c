/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:01:45 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/04 23:01:55 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *) s1)[idx] != ((unsigned char *) s2)[idx])
			return (((unsigned char *) s1)[idx] - ((unsigned char *) s2)[idx]);
		idx++;
	}
	return (0);
}
