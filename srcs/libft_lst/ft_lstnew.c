/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:09:55 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/12 20:21:16 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

t_node	*ft_lstnew(int num, int idx)
{
	t_node	*node;

	node = (t_node*) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
