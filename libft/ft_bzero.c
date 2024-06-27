/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:54:39 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/04 22:54:46 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	idx;
	unsigned char	*dest;

	idx = 0;
	dest = (unsigned char *) s;
	while (idx < n)
		dest[idx++] = '\0';
}
