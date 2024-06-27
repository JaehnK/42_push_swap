/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:51:47 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:51:17 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_putnbru(unsigned int n, int cnt)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		cnt += write(1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		cnt += ft_putnbru(n / 10, cnt);
		cnt += write(1, &c, 1);
	}
	return (cnt);
}

int	print_udec(va_list ap)
{
	unsigned int	n;
	int				cnt;

	cnt = 0;
	n = va_arg(ap, unsigned int);
	return (ft_putnbru(n, cnt));
}
