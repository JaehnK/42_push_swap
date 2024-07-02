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

void	ra(t_stack *a, int verbose)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->head;
	a->head = a->head->next;
	a->head->prev = NULL;
	a->tail->next = node;
	node->prev = a->tail;
	a->tail = node;
	if (verbose)
		write(1, "ra\n", 3);
}
void	rb(t_stack *b, int verbose)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->head;
	b->head = b->head->next;
	b->head->prev = NULL;
	b->tail->next = node;
	node->prev = b->tail;
	b->tail = node;
	if (verbose)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, int verbose)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (verbose)
		write(1, "rr\n", 3);
}