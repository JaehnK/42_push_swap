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
 
//static void	ft_dup_chk(t_stack *stk)
//{
//	int	i;
//	int	j;

//	i = 0;
//	while (i < stk->len_a)
//	{
//		j = i + 1;
//		while (j < stk->len_a)
//		{
//			if (stk->a[i] == stk->a[j])
//				ft_error();
//			j++;
//		}
//		i++;
//	}
//	return ;
//}

//int	ft_sort_chka(t_stack *stk)
//{
//	int	idx;
//	int	max;

//	idx = 1;
//	max = stk->a[0];
//	while (idx <= stk->len_a)
//	{
//		if (stk->a[idx] >= max)
//			max = stk->a[idx];
//		else
//			return (0);
//		idx++;
//	}
//	return (1);
//}

//int	ft_sort_chkb(t_stack *stk)
//{
//	int	idx;
//	int	max;

//	idx = 1;
//	max = stk->b[0];
//	while (idx <= stk->len_b)
//	{
//		if (stk->b[idx] >= max)
//			max = stk->b[idx];
//		else
//			return (0);
//		idx++;
//	}
//	return (1);
//}

//void	ft_dup_srt_chk(t_stack *stk)
//{
//	ft_dup_chk(stk);
//	if (ft_sort_chka(stk))
//		ft_error();
//}
