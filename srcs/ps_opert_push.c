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

void	pa(t_stack *a, t_stack *b, int verbose)
{
	t_node *pop;

	if (!b->head)
		return ;
	pop = b->head;
	b->head = pop->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	b->size--;
	pop->next = a->head;
	if (a->head)
		a->head->prev = pop;
	if (!a->tail)
		a->tail = pop;
	a->head = pop;
	a->size++;
	if (verbose)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int verbose)
{
	t_node *pop;

	if (!a->head)
		return ;
	pop = a->head;
	a->head = pop->next;
	a->size--;
	if (a->head)
		a->head->prev = NULL;
	else
		b->tail = NULL;
	pop->next = b->head;
	if (b->head)
		b->head->prev = pop;
	if(!b->tail)
		b->tail = pop;
	b->head = pop;
	b->size++;
	if (verbose)
		write(1, "pb\n", 3);
}