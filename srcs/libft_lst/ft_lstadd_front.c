/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:24:52 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/13 20:05:46 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../includes/push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
