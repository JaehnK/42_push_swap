/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:30:30 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:50:21 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static ssize_t	check_percent(const char *input, int *idx)
{
	if (input[*idx] == '%')
	{
		if (ft_strchr("cspdiuxX%", input[*idx + 1]))
		{
			*idx += 2;
			return (1);
		}
		else
			return (-1);
	}
	return (0);
}

static int	push_percent(const char *input, int idx, va_list ap)
{
	int	len;

	len = 0;
	if (input[idx - 1] == 'c')
		len = print_char(ap);
	else if (input[idx - 1] == 's')
		len = print_str(ap);
	else if (input[idx - 1] == 'p')
		len = print_addr(ap);
	else if (input[idx - 1] == 'd')
		len = print_dec(ap);
	else if (input[idx - 1] == 'i')
		len = print_dec(ap);
	else if (input[idx - 1] == 'u')
		len = print_udec(ap);
	else if (input[idx - 1] == 'x')
		len = print_hex(ap, 0);
	else if (input[idx - 1] == 'X')
		len = print_hex(ap, 1);
	else if (input[idx - 1] == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		len;
	int		idx;
	va_list	ap;

	len = 0;
	idx = 0;
	va_start(ap, input);
	while (input[idx])
	{
		if (check_percent(input, &idx) == 1)
			len += push_percent(input, idx, ap);
		else if (check_percent(input, &idx) == 0)
			len += write(1, &input[idx++], 1);
		else
			return (-1);
	}
	return (len);
}
