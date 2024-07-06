/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:15:26 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/06 16:15:27 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_cmd(t_cmdlist **lst, char *cmd)
{
	t_cmd	*node;
	t_cmd	*tmp;

	node = (t_cmd *) malloc(sizeof(t_cmd));
	node->cmd = cmd;
	node->next = NULL;
	if ((*lst)->head != NULL)
	{
		tmp = (*lst)->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}	
	else
		(*lst)->head = node;
}

void	ft_optim_cmds(t_cmd **node, char *str)
{
	t_cmd	*tmp;

	(*node)->cmd = str;
	tmp = (*node)->next->next;
	free((*node)->next);
	(*node)->next = tmp;
}

void	ft_print_cmd(t_cmdlist **lst)
{
	t_cmd	*node;
	t_cmd	*tmp;

	node = (*lst)->head;
	while (node->next)
	{
		write(1, node->cmd, ft_strlen(node->cmd));
		tmp = node;
		node = node->next;
		free(tmp);
	}
	write(1, node->cmd, ft_strlen(node->cmd));
	free(node);
	free(*lst);
}
