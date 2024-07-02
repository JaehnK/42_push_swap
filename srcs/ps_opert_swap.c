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

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack *a, int verbose)
{
	t_node	*node;
	
	if (a->size)
		return ;
	node = a->head;
	a->head = a->head->next;
	node->next = a->head->next;
	node->prev = a->head;
	a->head->next = node;
	a->head->prev = NULL;
	if (verbose)
		write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack *b, int verbose)
{
	t_node	*node;
	
	if (b->size)
		return ;
	node = b->head;
	b->head = b->head->next;
	node->next = b->head->next;
	node->prev = b->head;
	b->head->next = node;
	b->head->prev = NULL;
	if (verbose)
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack *a, t_stack *b, int verbose)
{
	sa(a, 0);
	sb(b, 0);
	if (verbose)
		write(1, "ss\n", 3);
	return ;
}
