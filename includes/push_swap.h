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

typedef struct s_node
{
	int				num;
	int				rank;
	char			*base;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_radix
{
	int	zeros;
	int	ones;
	int	twos;
}	t_radix;

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmdlist
{
	t_cmd	*head;
	int		size;
}	t_cmdlist;

void	ft_error(void);
void	ft_check_ag(int argc, char **argv);
t_stack	*ft_init_stack(int argc, char **argv);
t_stack	*ft_init_stk_b(void);
void	ft_dup_srt_chk(t_stack *a);
t_node	*ft_lstnew(int num);
void	ft_lstadd_front(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node **new);
void	ft_lstdelone(t_node *lst, void (*del)(void *));
void	ft_lstclear(t_node **lst, void (*del)(void *));
void	ft_lstiter(t_node *lst, char *(*f)(int));
void	ft_print_lst(t_stack *a, t_stack *b);
void	swap(int *a, int *b);
void	sa(t_stack *a, t_cmdlist *lst, int verbose);
void	sb(t_stack *b, t_cmdlist *lst, int verbose);
void	ss(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose);
void	pa(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose);
void	pb(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose);
void	ra(t_stack *a, t_cmdlist *lst, int verbose);
void	rb(t_stack *b, t_cmdlist *lst, int verbose);
void	rr(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose);
void	rra(t_stack *a, t_cmdlist *lst, int verbose);
void	rrb(t_stack *b, t_cmdlist *lst, int verbose);
void	rrr(t_stack *a, t_stack *b, t_cmdlist *lst, int verbose);
void	ft_push_swap(t_stack *a, t_stack *b, t_cmdlist *lst);
void	ft_radix_sort(t_stack *a, t_stack *b, t_cmdlist *lst);
void	ft_tiny_sort(t_stack *a, t_stack *b, t_cmdlist *lst);
void	ft_convert_rank(t_stack **rank);
void	ft_add_cmd(t_cmdlist **lst, char *cmd);
void	ft_print_cmd(t_cmdlist **lst);
void	ft_sort_three(t_stack *a, t_cmdlist *lst);
void	ft_sort_five(t_stack *a, t_stack *b, t_cmdlist *lst);
#endif