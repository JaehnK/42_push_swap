/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:37:57 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/02 09:37:59 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_2dim(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	ft_alloc_lst(t_node **head, int start, int len, char **nums)
{
	int		idx;
	t_node	*node;

	idx = start;
	while (idx < len)
	{
		node = ft_lstnew(ft_atoi(nums[idx]), idx);
		if (idx == start)
			*head = node;
		else
			ft_lstadd_back(head, &node);
		idx++;
	}
}

t_stack	*ft_init_stack(int argc, char **argv)
{
	int		idx;
	char	**tmp;
	t_node	*head;
	t_stack	*stk;

	idx = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[idx])
			idx++;
		ft_alloc_lst(&head, 0, idx, tmp);
		ft_free_2dim(tmp);
	}
	else
		ft_alloc_lst(&head, 1, argc, argv);
	stk = (t_stack *) malloc(sizeof(t_stack));
	stk->head = head;
	stk->tail = ft_lstlast(head);
	stk->size = ft_lstsize(head);
	return (stk);
}

t_stack *ft_init_stk_b(void)
{
	t_stack *stk;

	stk = (t_stack *) malloc(sizeof(t_stack));
	stk->head = NULL;
	stk->tail = NULL;
	stk->size = 0;
	return (stk);
}