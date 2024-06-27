/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrhcr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:59:59 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/04 23:00:08 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p != '\0')
		p++;
	while (p >= s)
	{
		if (*p == c)
			return (p);
		else
			p--;
	}
	return (NULL);
}
