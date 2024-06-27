/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:54:19 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/13 22:08:30 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_digit(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		cnt++;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dest;

	i = count_digit(n);
	dest = (char *) malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	if (n < 0)
		dest[0] = '-';
	dest[i] = '\0';
	if (n == 0)
		dest[0] = '0';
	while (n)
	{
		if (n % 10 < 0)
			dest[--i] = n % 10 * -1 + '0';
		else
			dest[--i] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
