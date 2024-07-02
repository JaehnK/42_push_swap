/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:30:02 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/13 21:06:23 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../includes/push_swap.h"

void	ft_lstiter(t_node *lst, char *(*f)(int))
{
	while (lst)
	{
		lst->base = f(lst->num);
		lst = lst->next;
	}
}
