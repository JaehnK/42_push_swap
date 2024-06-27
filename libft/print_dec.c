/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:40:01 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:50:59 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_putnbr(int n, int cnt)
{
	char	c;

	if (n == -2147483648)
	{
		cnt += write(1, "-2147483648", 11);
		return (cnt);
	}
	else if (n < 0)
	{
		cnt += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10 && n >= 0)
	{
		c = n + '0';
		cnt += write(1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		cnt += ft_putnbr(n / 10, 0);
		cnt += write(1, &c, 1);
	}
	return (cnt);
}

int	print_dec(va_list ap)
{
	int	n;
	int	cnt;

	cnt = 0;
	n = va_arg(ap, int);
	return (ft_putnbr(n, cnt));
}
