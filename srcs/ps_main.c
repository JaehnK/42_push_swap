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

void	ft_print_stacks(t_stacks *stk)
{
	int	idx;

	idx = 0;
	while (!(idx >= stk->len_a) || !(idx >= stk->len_b))
	{
		if (idx < stk->len_a)
			ft_printf("%d  ", stk->a[idx]);
		else
			ft_printf("N  ");
		if (idx < stk->len_b)
			ft_printf("%d\n", stk->b[idx]);
		else
			ft_printf("N\n");
		idx++;
	}
	ft_printf("----\na  b\n");
}

int	main(int argc, char **argv)
{
	int			idx;
	t_stacks	*stack;

	idx = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_check_ag(argc, argv);
	ft_init_stack(&stack, argc, argv);
	ft_dup_srt_chk(stack);
	ft_push_swap(stack);
	free(stack->a);
	free(stack->b);
	free(stack);
	return (EXIT_SUCCESS);
}
