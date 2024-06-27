/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dupchk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:36:54 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 11:36:55 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_dup_chk(t_stacks *stk)
{
	int	idx;
	int	*dup_arr;

	idx = 0;
	dup_arr = (int *) ft_calloc(sizeof(int), (stk->max - stk->min + 4));
	while (idx < stk->len_a)
	{
		dup_arr[stk->a[idx] - stk->min]++;
		// ft_printf("idx : %d val: %d\n", stk->a[idx] - stk->min, dup_arr[stk->a[idx] - stk->min]);
		if (dup_arr[stk->a[idx] - stk->min] > 1)
			ft_error();
		idx++;
	}
	free(dup_arr);
}

static void	ft_sort_chk(t_stacks *stk)
{
	int	idx;
	int	max;

	idx = 1;
	max = stk->a[0];
	while (idx <= stk->len_a)
	{
		if (stk->a[idx] >= max)
			max = stk->a[idx];
		else
			return;
		idx++;
	}
	ft_error();
}

void	ft_dup_srt_chk(t_stacks *stk)
{
	ft_dup_chk(stk);
	ft_sort_chk(stk);
}