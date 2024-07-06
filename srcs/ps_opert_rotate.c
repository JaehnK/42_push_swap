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

void	ra(t_stack *a, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (a->size < 2)
		return ;
	node = a->head;
	a->head = a->head->next;
	a->head->prev = NULL;
	node->prev = ft_lstlast(a->head);
	node->next = NULL;
	ft_lstlast(a->head)->next = node;
	a->tail = node;
	if (verbose)
		ft_add_cmd(&lst, "ra\n");
}

void	rb(t_stack *b, t_cmdlist *lst, int verbose)
{
	t_node	*node;

	if (b->size < 2)
		return ;
	node = b->head;
	b->head = b->head->next;
	b->head->prev = NULL;
	node->prev = ft_lstlast(b->head);
	node->next = NULL;
	ft_lstlast(b->head)->next = node;
	b->tail = node;
	if (verbose)
		ft_add_cmd(&lst, "rb\n");
}

void	rr(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose)
{
	if (a->size < 2 || b->size < 2)
		return ;
	ra(a, lst, 0);
	rb(b, lst, 0);
	if (verbose)
		ft_add_cmd(&lst, "rr\n");
}
