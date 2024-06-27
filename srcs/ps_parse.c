/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:36:37 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/26 19:38:40 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void ft_cpy_arr(char **tmp, t_stacks **stack)
{
	int	i;

	i = 0;
	(*stack)->min = INT_MAX;
	(*stack)->max = INT_MIN;
	while (tmp[i])
	{
		(*stack)->a[i] = ft_atoi(tmp[i]);
		if ((*stack)->min > (*stack)->a[i])
			(*stack)->min = (*stack)->a[i];
		if ((*stack)->max < (*stack)->a[i])
			(*stack)->max = (*stack)->a[i];
		i++;
	}
}

static void	ft_free_2dim(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static void ft_alloc_stack(t_stacks **stack, char **src, int len)
{
	(*stack)->a = (int *) ft_calloc(sizeof(int), len + 5);
	(*stack)->b = (int *) ft_calloc(sizeof(int), len + 5);
	(*stack)->len_a = len;
	(*stack)->len_b = 0;
	ft_cpy_arr(src, stack);

}

void	ft_init_stack(t_stacks **stack, int argc, char **argv)
{
	char	**tmp;
	int		len;

	len = 0;
	*stack = (t_stacks *) malloc(sizeof(t_stacks));
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[len])
			len++;
		ft_alloc_stack(stack, tmp, len);
		ft_free_2dim(tmp);
	}
	else
		ft_alloc_stack(stack, ++argv, argc - 1);
}
