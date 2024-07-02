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

void	rra(t_stack *a, int verbose)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->tail;
	node->prev = NULL;
	node->next = a->head;
	a->tail = a->tail->prev;
	a->head->prev = node;
	a->head = node;
	if (verbose)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int verbose)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->tail;
	node->prev = NULL;
	node->next = b->head;
	b->tail = b->tail->prev;
	b->head->prev = node;
	b->head = node;
	if (verbose)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int verbose)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rra(a, 0);
	rrb(b, 0);
	if (verbose)
		write(1, "rrr\n", 4);
}