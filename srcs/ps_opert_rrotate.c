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

void	rra(t_stack *a, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->tail;
	a->tail = a->tail->prev;
	if (a->tail)
		a->tail->next = NULL;
	node->prev = NULL;
	node->next = a->head;
	a->head->prev = node;
	a->head = node;
	if (verbose)
		ft_add_cmd(&lst, "rra\n");
}

void	rrb(t_stack *b, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->tail;
	b->tail = b->tail->prev;
	if (b->tail)
		b->tail->next = NULL;
	node->prev = NULL;
	node->next = b->head;
	b->head->prev = node;
	b->head = node;
	if (verbose)
		ft_add_cmd(&lst, "rrb\n");
}

void	rrr(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rra(a, lst, 0);
	rrb(b, lst, 0);
	if (verbose)
		ft_add_cmd(&lst, "rrr\n");
}
