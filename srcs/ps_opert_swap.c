/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opert_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:06:12 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 14:06:13 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stacks *stk, int verbose)
{
	if (stk->len_a < 2)
		return ;
	swap(&(stk->a[0]), &(stk->a[1]));
	if (verbose)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stk, int verbose)
{
	if (stk->len_b < 2)
		return ;
	swap(&(stk->b[0]), &(stk->b[1]));
	if (verbose)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stk, int verbose)
{
	sa(stk, 0);
	sb(stk, 0);
	if (verbose == 1)
		write(1, "ss\n", 3);
}
