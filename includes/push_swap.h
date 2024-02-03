/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 21:01:58 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_stack
{
	t_list	*a_top;
	t_list	*b_top;
}			t_stack;

typedef struct s_parts
{
	int		min;
	int		low_mid;
	int		mid;
	int		high_mid;
	int		max;
}			t_parts;

typedef struct s_input
{
	int		*arr;
	char	*args;
	int		*control;
	int		nr_count;
}			t_input;

typedef struct s_rot
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		cost;
}			t_rot;

//to be changed
int		*parse_numbers(t_input *input);
t_stack	*init_input(t_input *input);
void	find_parts(t_parts *p, t_input *input);
void	print_content(void *content);
void	print_current_stacks(t_stack *stack);

//rotations-finding
t_rot	find_best_rotation(t_stack *stack, t_input *input, t_parts *p);
int		find_a_spot(t_stack *stack);
t_list	*node_at_index(t_list *list, int a_index);
void	both_up(t_stack *stack,int a_idx, int b_idx, t_rot *rot);
void	both_down(t_stack *stack,int a_idx, int b_idx, t_rot *rot);
void	up_down(t_stack *stack,int a_idx, int b_idx, t_rot *rot);
void	down_up(t_stack *stack,int a_idx, int b_idx, t_rot *rot);
void	set_cost(t_rot *rot);
void	execute_best(t_rot best, t_stack *stack);
void	finish_rotations(t_stack *stack, t_input *input);

//quick-sort
void	quick_sort(int *arr, int start, int end);
int		partition(int *arr, int start, int end);

//push-swap
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
int		is_sorted(t_list *list, int min);
void	sort_bps(t_stack *stack, t_input *input, t_parts *p);
int		is_breakpoint(int content, t_parts *p, t_input *input);
t_list	*pluck_first(t_list **lst);
void	push_l_to_b(t_stack *stack, t_input *input, t_parts *p);
void	push_h_to_b(t_stack *stack, t_input *input, t_parts *p);
#endif