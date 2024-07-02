/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:09:13 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/13 20:58:43 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../includes/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node **new)
{
	t_node	*first;
	t_node	*last;

	first = *lst;
	if (!lst || !*new)
		return ;
	if (*lst == NULL)
	{
		*lst = *new;
		return ;
	}
	last = ft_lstlast(*lst);
	(*new)->prev = last;
	last->next = *new;
	*lst = first;
}
