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

void	radix_original(t_stack *a, t_stack *b, int idx)
{
	int cnt;

	cnt = a->size + b->size;
	while (cnt && a->head)
	{
		if (a->head->base[idx] == '0')
			ra(a, 1);
		else if (a->head->base[idx] == '1')
			pb(a, b, 1);
		else if (a->head->base[idx] == '2')
		{
			pb(a, b, 1);
			rb(b, 1);
		}
		cnt --;
	}
}
void	merge_original(t_stack *a, t_stack *b)
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


int	radix_a(t_stack *a, t_stack *b, int idx)
{
	int cnt;
	int	base_cnt;

	base_cnt = 0;
	cnt = a->size + b->size;
	while (cnt && a->head)
	{
		if (a->head->base[idx] == '0')
			ra(a, 1);
		else if (a->head->base[idx] == '1')
			pb(a, b, 1);
		else if (a->head->base[idx] == '2')
		{
			pb(a, b, 1);
			rb(b, 1);
			base_cnt++;
		}
		cnt --;
	}
	return (base_cnt);
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

void	merge_b(t_stack *a, t_stack *b)
{
	int	cnt;
	
	cnt = a->size;
	while (cnt)
	{
		pa(a, b, 1);
		rb(b, 1);
		cnt --;
	}

}


void	ft_radix_sort(t_stack *a, t_stack *b)
{
	int	base;
	int	base_cnt;
	int max_base;

	base = 0;
	max_base = ft_chk_maxbase(a, b);
	base_cnt = 0;
	printf("max %d\n", max_base);
	while (base < max_base)
	{
		if (base % 2 == 0)
		{
			base_cnt = radix_a(a, b, base);
			merge_b(a, b);
		}
		else if (base % 2 == 1)
		{
			base_cnt = radix_b(a, b, base);
			merge_a(a, b);
		}
		base++;
	}	
}
