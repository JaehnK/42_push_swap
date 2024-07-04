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

t_radix	radix_original(t_stack *a, t_stack *b, int idx)
{
	int cnt;
	t_radix base_cnt;

	cnt = a->size + b->size;
	while (cnt && a->head)
	{
		if (a->head->base[idx] == '0')
		{
			ra(a, 1);
			base_cnt.zeros++;
		}
		else if (a->head->base[idx] == '1')
		{
			pb(a, b, 1);
			base_cnt.ones++;
		}
		else if (a->head->base[idx] == '2')
		{
			pb(a, b, 1);
			rb(b, 1);
			base_cnt.twos++;
		}
		cnt --;
	}
	return (base_cnt);
}

void	merge_original(t_stack *a, t_stack *b, t_radix base_cnt)
{
	int	cnt;
	int	idx;

	idx = 0;
	cnt = b->size;
	printf("%d %d %d\n", base_cnt.zeros, base_cnt.ones, base_cnt.twos);
	while (idx < cnt)
	{
			pa(a, b, 1);
			ra(a, 1);
		idx++;
	}

}

int	ft_get_digits_len(int num)
{	
	int	digits;

	digits = 0;
	while (num)
	{
		num /= 3;
		digits++;
	}
	return (digits);
}

int	ft_chk_maxbase(t_stack *a, t_stack *b)
{
	int		max;
	int		digits;
	t_node	*tmp;

	max = 0;
	tmp = a->head;
	while (tmp)
	{
		digits = ft_get_digits_len(tmp->num);
		if (max <= digits)
			max = digits;
		tmp = tmp->next;
	}
	return (max);
}

void	radix_a(t_stack *a, t_stack *b, int idx, t_radix **base_cnt)
{
	int cnt;

	cnt = a->size + b->size;
	while (cnt && a->head)
	{
		if (a->head->base[idx] == '0')
		{
			ra(a, 1);
			(*base_cnt)->zeros++;
		}
		else if (a->head->base[idx] == '1')
		{
			pb(a, b, 1);
			
			(*base_cnt)->ones++;
		}
		else if (a->head->base[idx] == '2')
		{
			pb(a, b, 1);
			rb(b, 1);
			(*base_cnt)->twos;
		}
		cnt --;
	}
}

int	radix_b(t_stack *a, t_stack *b, int idx)
{
	int	cnt;
	int	base_cnt;

	cnt = a->size + b->size;
	base_cnt = 0;
	while (cnt && b->head)
	{
		if (b->head->base[idx] == '0')
			rb(b, 1);
		else if (b->head->base[idx] == '1')
			pa(a, b, 1);
		else if (b->head->base[idx] == '2')
		{
			pa(a, b, 1);
			ra(a, 1);
			base_cnt++;
		}
		cnt --;
	}
	return (base_cnt);
}

void	merge_a(t_stack *a, t_stack *b)
{

	int	cnt;
	
	cnt = b->size;
	while (cnt)
	{
		pa(a, b, 1);
		ra(a, 1);
		cnt --;
	}

}

void	merge_b(t_stack *a, t_stack *b, t_radix *base_cnt)
{
	int	idx;
	int	len;

	idx = 0;	
	len = b->size;
	while (idx++ < base_cnt->ones)
		pa(a, b, 1);
	idx = 0;
	while (idx++ < base_cnt->ones)
		ra(a,1);
	while (idx < len + 1)
	{
		pa(a, b, 1);
		ra(a, 1);
		idx++;
	}
}


void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int		base;
	int 	max_base;
	t_radix *base_cnt;

	base = 0;
	max_base = ft_chk_maxbase(a, b);
	base_cnt = (t_radix *) malloc(sizeof(t_radix));
	while (base < max_base)
	{
		base_cnt->ones = 0;
		base_cnt->twos = 0;
		base_cnt->zeros = 0;
		radix_a(a, b, base, &base_cnt);
		merge_b(a, b, base_cnt);
		base++;
	}	
}
