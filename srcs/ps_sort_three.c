/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:14:21 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/30 17:14:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three1(t_stacks *stk)
{
		if ((stk->a[1] < stk->a[2]))
			return ;
		else
		{
			rra(stk, 1);
			sa(stk, 2);
		}
	}

void	ft_sort_three2(t_stacks *stk)
{
		if ((stk->a[1] < stk->a[2]))
			ra(stk, 1);
		else
		{
			ra(stk, 1);
			sa(stk, 1);
		}
}

void	ft_sort_unders_three(t_stacks *stk)
{
	if (stk->len_a == 2)
	{
		if (stk->a[0] > stk->a[1])
			sa(stk, 1);
	}
	if ((stk->a[0] < stk->a[1]) && (stk->a[0] < stk->a[2]))
		ft_sort_three1(stk);
	else if ((stk->a[0] > stk->a[1]) && (stk->a[0] > stk->a[2]))
		ft_sort_three2(stk);
	else
	{
		if ((stk->a[1] < stk->a[2]))
			sa(stk, 1);
		else
			rra(stk, 1);
	}
}
