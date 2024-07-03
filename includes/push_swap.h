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
# include "../libft/libft.h"

typedef	struct	s_node
{
	int				num;
	int				idx;
	char			*base;
	struct	s_node	*next;
	struct	s_node	*prev;
}	t_node;

typedef struct	s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;



void	ft_error(void);
void	ft_check_ag(int argc, char **argv);
t_stack	*ft_init_stack(int argc, char **argv);
t_stack *ft_init_stk_b(void);

//int		ft_sort_chka(t_stack *stk);
//int		ft_sort_chkb(t_stack *stk);
void	ft_dup_srt_chk(t_stack *a);
//void	ft_print_stacks(t_stack *stk);

t_node	*ft_lstnew(int num, int idx);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node **new);
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, char *(*f)(int));
void	ft_print_lst(t_stack *a, t_stack *b);
void	swap(int *a, int *b);
void	sa(t_stack *a, int verbose);
void	sb(t_stack *b, int verbose);
void	ss(t_stack *a, t_stack *b, int verbose);
void	pa(t_stack *a, t_stack *b, int verbose);
void	pb(t_stack *a, t_stack *b, int verbose);
void	ra(t_stack *a, int verbose);
void	rb(t_stack *b, int verbose);
void	rr(t_stack *a, t_stack *b, int verbose);
void	rra(t_stack *a, int verbose);
void	rrb(t_stack *b, int verbose);
void	rrr(t_stack *a, t_stack *b, int verbose);
void	ft_push_swap(t_stack *a, t_stack *b);
void	ft_radix_sort(t_stack *a, t_stack *b);
void	ft_tiny_sort(t_stack *a);
#endif