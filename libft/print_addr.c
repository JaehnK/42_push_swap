/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:01:40 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:50:38 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_puthex(int i, int upper)
{
	char	c;

	if (i % 16 < 10)
		c = i % 16 + 48;
	else
	{
		if (!upper)
			c = i % 16 + 87;
		else
			c = i % 16 + 55;
	}
	write(1, &c, 1);
	return (1);
}

static int	ft_long2hex(unsigned long long int addr, int isupper, int cnt)
{
	if (addr < 16)
	{
		return (ft_puthex(addr, isupper));
	}
	else
	{
		cnt += ft_long2hex(addr / 16, 0, cnt);
		cnt += ft_long2hex(addr % 16, 0, cnt);
	}
	return (cnt);
}

static int	ft_int2hex(unsigned int addr, int isupper, int cnt)
{
	if (addr < 16)
	{
		return (ft_puthex(addr, isupper));
	}
	else
	{
		cnt += ft_int2hex(addr / 16, isupper, cnt);
		cnt += ft_int2hex(addr % 16, isupper, cnt);
	}
	return (cnt);
}

int	print_addr(va_list ap)
{
	int					cnt;
	void				*ptr;
	unsigned long long	addr;

	cnt = 0;
	ptr = va_arg(ap, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	write(1, "0x", 2);
	cnt = ft_long2hex(addr, 0, cnt);
	return (cnt + 2);
}

int	print_hex(va_list ap, int isupper)
{
	int					cnt;
	unsigned long long	num;

	cnt = 0;
	num = va_arg(ap, unsigned int);
	return (ft_int2hex(num, isupper, cnt));
}	
