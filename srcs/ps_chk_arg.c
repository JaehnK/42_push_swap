/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:16:22 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/26 13:16:24 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_char(char *str, int chk_spc)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && chk_spc)
			return (1);
		if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_ag(int argc, char **argv)
{
	int		idx;

	idx = 1;
	if (argc == 2)
	{
		if (ft_check_char(argv[idx], 0))
			ft_error();
	}
	else if (argc > 2)
	{
		while (idx < argc)
		{
			if (ft_check_char(argv[idx++], 1))
				ft_error();
		}
	}
}
