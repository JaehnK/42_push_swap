/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:04:32 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/30 17:04:35 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b)
{
	
	if (a->size < 4)
		ft_tiny_sort(a);
	else
		ft_radix_sort(a, b);
	return ;
}
