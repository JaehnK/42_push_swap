/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:02:09 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/11 22:26:34 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i_l;

	if (!big && !little)
		return (NULL);
	if (!big && !len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		i_l = 0;
		while (little[i_l] == big[i + i_l] && i + i_l < len)
		{
			i_l++;
			if (little[i_l] == '\0')
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
