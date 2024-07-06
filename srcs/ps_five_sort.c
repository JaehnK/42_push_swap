/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_five_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:23:11 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/07 01:23:38 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rank_cnt(t_stack *a, int rank)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->head;
	while (tmp->rank != rank)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_mouve_to_b(t_stack *a, t_stack *b, t_cmdlist *lst, int rank)
{
	int	cnt;

	cnt = ft_rank_cnt(a, rank);
	if (cnt < 2)
	{
		while (a->head->rank != rank)
			ra(a, lst, 1);
		pb(a, b, lst, 1);
	}
	else
	{
		while (a->head->rank != rank)
			rra(a, lst, 1);
		pb(a, b, lst, 1);
	}
}

void	ft_sort_five(t_stack *a, t_stack *b, t_cmdlist *lst)
{
	ft_mouve_to_b(a, b, lst, 0);
	ft_mouve_to_b(a, b, lst, 1);
	ft_sort_three(a, lst);
	pa(a, b, lst, 1);
	pa(a, b, lst, 1);
}
