/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:18:22 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/04 17:18:45 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bubble_sort(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{	
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_convert_rank(t_stack **stk)
{
	int		i;
	int		idx;
	int		*arr;
	t_node	*node;

	idx = 0;
	arr = (int *) malloc(sizeof(int) * ((*stk)->size + 1));
	node = (*stk)->head;
	while (idx < (*stk)->size)
	{
		arr[idx++] = node->num;
		node = node->next;
	}
	ft_bubble_sort(arr, (*stk)->size);
	node = (*stk)->head;
	while (node)
	{
		i = 0;
		while (arr[i] != node->num)
			i++;
		node->rank = i;
		node = node->next;
	}
	free(arr);
}
