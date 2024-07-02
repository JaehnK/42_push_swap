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

void	ft_print_lst(t_stack *a, t_stack *b)
{
	int		idx = 0;
	t_node	*a_node = a->head;
	t_node	*b_node = b->head;

	printf("a_size : %d b_size : %d\n", a->size, b->size);
	while (idx < a->size || idx < b->size)
	{
		if (idx <= a->size)
		{
			printf("%d  ", a_node->num);
			a_node = a_node->next;
		}
		else
			printf("N  ");
		if (idx < b->size)
		{
			printf("%d\n", b_node->num);
			b_node = b_node->next;
		}
		else
			printf("N\n");
		idx++;
	}
	printf("------\na  b\n");
}

int	main(int argc, char **argv)
{
	int			idx;
	t_stack		*a;
	t_stack		*b;

	idx = 0;
	if (argc < 2)
		exit(EXIT_FAILURE);
	ft_check_ag(argc, argv);
	a = ft_init_stack(argc, argv);
	b = ft_init_stk_b();
	pb(a, b, 1);
	pb(a, b, 1);
	pb(a, b, 1);
	ft_print_lst(a, b);
	rra(a, 1);
	ft_print_lst(a, b);
	rrb(b, 1);
	ft_print_lst(a, b);
	//ft_init_stack(&stack, argc, argv);
	//ft_dup_srt_chk(stack);
	//ft_push_swap(stack);
	//free(stack->a);
	//free(stack->b);
	//free(stack);
	return (EXIT_SUCCESS);
}
