/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:28:28 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/03 11:28:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

char	*ft_get_3digit(int n)
{
	int		idx;
	int		mok;
	char	*digit;

	idx = 0;
	if (n == INT_MIN)
		return ("20120201121222121121_");
	digit = (char *) malloc(sizeof(char) * 22);
	if (!digit)
		ft_error();
	if (n < 0)
	{
		digit[20] = '-';
		n *= -1;
	}
	else
		digit[20] = '+';
	while (idx < 20)
	{
		digit[idx++] = (n % 3) + '0';
		n /= 3;
	}
	digit[21] = '\0';
	return (digit);
}

int	main(int argc, char **argv)
{
	char *n = ft_get_3digit(INT_MIN);
	free(n);

}
