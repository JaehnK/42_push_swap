/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:33:27 by jaehukim          #+#    #+#             */
/*   Updated: 2024/03/13 21:01:40 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

void	ft_lstdelone(t_node *lst, void (*del) (void *))
{
	if (!lst || !del)
		return ;
	del((void *)lst->base);
	free(lst);
}
