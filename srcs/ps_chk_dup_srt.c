/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_dupchk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:36:54 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/27 11:36:55 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_dup_chk(t_stack *a)
{
	t_node	*pivot;
	t_node	*rotate;

	pivot = a->head;
	while (pivot)
	{
		rotate = pivot->next;
		while (rotate)
		{
			if (pivot->num == rotate->num)
				ft_error();
			rotate = rotate->next;
		}
		pivot = pivot->next;
	}
	return ;
}

int	ft_sort_chk(t_stack *stk)
{
	int		max;
	t_node	*tmp;

	tmp = stk->head->next;
	max = stk->head->num;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_dup_srt_chk(t_stack *a)
{
	ft_dup_chk(a);
	if (a->size < 2)
		exit(EXIT_SUCCESS);
	if (ft_sort_chk(a))
		exit(EXIT_FAILURE);
}
