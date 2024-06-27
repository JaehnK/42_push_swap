/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opert_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:47:05 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 14:47:07 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks *stk, int verbose)
{
	if (!stk->len_b)
		return;
	
	ft_memmove((void *) stk->a + 4, (void *)stk->a, stk->len_a * sizeof(int));
	stk->a[0] = stk->b[0];
	ft_memmove((void *) stk->b, (void *) stk->b + 4, stk->len_b * sizeof(int));
	stk->len_a++;
	stk->len_b--;
	if (verbose)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stk, int verbose)
{
	if (!stk->len_a)
		return;
	
	ft_memmove((void *) stk->b + 4, (void *) stk->b, stk->len_b * sizeof(int));
	stk->b[0] = stk->a[0];
	ft_memmove((void *) stk->a, (void *) stk->a + 4, (stk->len_a - 1)* sizeof(int));
	stk->len_b++;
	stk->len_a--;
	if (verbose)
		write(1, "pb\n", 3);
}
