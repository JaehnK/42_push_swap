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

void	sa(t_stack *a, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->head;
	a->head = a->head->next;
	node->next = a->head->next;
	node->prev = a->head;
	a->head->next = node;
	a->head->prev = NULL;
	if (verbose)
		ft_add_cmd(&lst, "sa\n");
	return ;
}

void	sb(t_stack *b, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->head;
	b->head = b->head->next;
	node->next = b->head->next;
	node->prev = b->head;
	b->head->next = node;
	b->head->prev = NULL;
	if (verbose)
		ft_add_cmd(&lst, "sb\n");
	return ;
}

void	ss(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose)
{
	sa(a, lst, 0);
	sb(b, lst, 0);
	if (verbose)
		ft_add_cmd(&lst, "ss\n");
	return ;
}
