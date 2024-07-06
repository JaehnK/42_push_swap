/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:38:32 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/25 15:38:33 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_list(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	while ((*a)->head)
	{
		tmp = (*a)->head->next;
		free((*a)->head->base);
		free((*a)->head);
		(*a)->head = tmp;
	}
	while ((*b)->head)
	{
		tmp = (*b)->head->next;
		free((*b)->head->base);
		free((*b)->head);
		(*b)->head = tmp;
	}
	free(*a);
	free(*b);
}

int	main(int argc, char **argv)
{
	t_cmdlist		*lst;
	t_stack			*a;
	t_stack			*b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_check_ag(argc, argv);
	a = ft_init_stack(argc, argv);
	b = ft_init_stk_b();
	ft_dup_srt_chk(a);
	lst = (t_cmdlist *) malloc(sizeof(t_cmdlist));
	lst->head = NULL;
	ft_push_swap(a, b, lst);
	ft_free_list(&a, &b);
	return (EXIT_SUCCESS);
}
