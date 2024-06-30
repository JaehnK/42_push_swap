/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opert_rrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:42:28 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 15:42:28 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stk, int verbose)
{
	ft_memmove((void *) stk->a + 4, (void *) stk->a, stk->len_a * sizeof(int));
	stk->a[0] = stk->a[stk->len_a];
	if (verbose)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stk, int verbose)
{
	ft_memmove((void *) stk->b + 4, (void *) stk->b, stk->len_b * sizeof(int));
	stk->b[0] = stk->b[stk->len_b];
	if (verbose)
		write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stk, int verbose)
{
	rra(stk, 0);
	rrb(stk, 0);
	if (verbose)
		write(1, "rrr\n", 5);
}
