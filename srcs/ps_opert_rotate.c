/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opert_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:27:19 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 15:27:20 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks *stk, int verbose)
{
	stk->a[stk->len_a] = stk->a[0];
	ft_memmove((void *) stk->a, (void *) stk->a + 4, stk->len_a * sizeof(int));
	if (verbose)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *stk, int verbose)
{
	stk->b[stk->len_b] = stk->b[0];
	ft_memmove((void *) stk->b, (void *) stk->b + 4, stk->len_b * sizeof(int));
	if (verbose)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *stk, int verbose)
{
	ra(stk, 0);
	rb(stk, 0);
	if (verbose)
		write(1, "rr\n", 3);
}
