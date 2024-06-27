/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:40:46 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/25 15:43:41 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
#include "../libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
	int	min;
	int	max;
}	t_stacks;


void	ft_error(void);
void	ft_check_ag(int argc, char **argv);
void	ft_init_stack(t_stacks **stack, int argc, char **argv);
void	ft_dup_srt_chk(t_stacks *stack);
void	ft_print_stacks(t_stacks *stk);

void	sa(t_stacks *stk, int verbose);
void	sb(t_stacks *stk, int verbose);
void	ss(t_stacks *stk, int verbose);
void	pa(t_stacks *stk, int verbose);
void	pb(t_stacks *stk, int verbose);
void	ra(t_stacks *stk, int verbose);
void	rb(t_stacks *stk, int verbose);
void	rr(t_stacks *stk, int verbose);
#endif
