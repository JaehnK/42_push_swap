/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:02:32 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/04 23:02:41 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	get_num(char *nptr, int sign, long long n)
{
	if (!ft_strlen(nptr))
		ft_error();
	while (*nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		n += *nptr - '0';
		nptr++;
		if (n >= 2147483648 && sign == 1)
			ft_error();
		if (n >= 2147483649 && sign < 1)
			ft_error();
	}
	return ((int)n * sign);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	long long		num;
	char			*ptr;

	sign = 1;
	num = 0;
	ptr = (char *) nptr;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{	
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	return (get_num(ptr, sign, num));
}
