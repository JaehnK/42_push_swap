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

static void	ft_sort_three1(t_stack *a)
{
		if (a->tail->prev->num < a->tail->num)
			return ;
		else
		{
			rra(a, 1);
			sa(a, 1);
		}
	}

static void	ft_sort_three2(t_stack *a)
{
		if (a->tail->prev->num < a->tail->num)
			ra(a, 1);
		else
		{
			ra(a, 1);
			sa(a, 1);
		}
}

void	ft_tiny_sort(t_stack *a)
{
	t_node	*second;

	second = a->head->next;

	if (a->size == 2)
	{
		if (a->tail->num > a->head->num)
			sa(a, 1);
		return ;
	}
	if (a->head->num < second->num && \
		a->head->num < a->tail->num)
		ft_sort_three1(a);
	else if (a->head->num > second->num &&\
		 	a->head->num > a->tail->num)
		ft_sort_three2(a);
	else
	{
		if (a->head->next->num < a->tail->num)
			sa(a, 1);
		else
			rra(a, 1);
	}
}
