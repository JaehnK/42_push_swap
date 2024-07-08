/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:14:21 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/30 17:14:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_three1(t_stack *a, t_cmdlist *lst)
{
	if (a->tail->prev->num < a->tail->num)
		return ;
	else
	{
		rra(a, lst, 1);
		sa(a, lst, 1);
	}
}

static void	ft_sort_three2(t_stack *a, t_cmdlist *lst)
{
	if (a->tail->prev->num < a->tail->num)
		ra(a, lst, 1);
	else
	{
		ra(a, lst, 1);
		sa(a, lst, 1);
	}
}

void	ft_sort_three(t_stack *a, t_cmdlist *lst)
{
	t_node	*second;

	second = a->head->next;
	if (a->head->num < second->num && \
		a->head->num < a->tail->num)
		ft_sort_three1(a, lst);
	else if (a->head->num > second->num && \
			a->head->num > a->tail->num)
		ft_sort_three2(a, lst);
	else
	{
		if (a->head->next->num < a->tail->num)
			sa(a, lst, 1);
		else
			rra(a, lst, 1);
	}
}

void	ft_tiny_sort(t_stack *a, t_stack *b, t_cmdlist *lst)
{		
	if (a->size == 2)
	{
		if (a->tail->num < a->head->num)
			sa(a, lst, 1);
		return ;
	}
	if (a->size == 3)
		ft_sort_three(a, lst);
	else if (a->size == 4)
		ft_sort_four(a, b, lst);
	if (a->size == 5)
		ft_sort_five(a, b, lst);
}
