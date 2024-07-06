/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:18:43 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/03 11:18:46 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_digits_len(int num)
{	
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 2;
		digits++;
	}
	return (digits);
}

static int	ft_chk_maxbase(t_stack *a)
{
	int		max;
	int		digits;
	t_node	*tmp;

	max = 0;
	tmp = a->head;
	while (tmp)
	{
		digits = ft_get_digits_len(tmp->rank);
		if (max <= digits)
			max = digits;
		tmp = tmp->next;
	}
	return (max);
}

static void	radix(t_stack *a, t_stack *b, int idx, t_cmdlist *lst)
{
	int	cnt;

	cnt = ft_lstsize(a->head);
	while (cnt)
	{
		if (a->head->base[idx] == '1')
			ra(a, lst, 1);
		else if (a->head->base[idx] == '0')
			pb(a, b, lst, 1);
		cnt--;
	}
}

static void	merge(t_stack *a, t_stack *b, t_cmdlist *lst)
{
	int	idx;
	int	len;

	idx = 0;
	len = b->size;
	while (idx < len)
	{
		pa(a, b, lst, 1);
		idx++;
	}
}

void	ft_radix_sort(t_stack *a, t_stack *b, t_cmdlist *lst)
{
	int		base;
	int		max_base;

	base = 0;
	max_base = ft_chk_maxbase(a);
	while (base < max_base)
	{
		radix(a, b, base, lst);
		merge(a, b, lst);
		base++;
	}
}
