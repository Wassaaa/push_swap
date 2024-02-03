/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 16:30:55 by aklein           ###   ########.fr       */
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
//to be changed
int		*parse_numbers(t_input *input);
t_stack	*init_input(t_input *input);
void	find_parts(t_parts *p, t_input *input);
void	print_content(void *content);
void	print_current_stacks(t_stack *stack);

//quick-sort
void	quick_sort(int *arr, int start, int end);
int		partition(int *arr, int start, int end);

//push-swap
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rra(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
int		is_sorted(t_list *list, int min);
void	sort_bps(t_stack *stack, t_input *input, t_parts *p);
int		is_breakpoint(int content, t_parts *p, t_input *input);
t_list	*pluck_first(t_list **lst);
void	push_l_to_b(t_stack *stack, t_input *input, t_parts *p);
void	push_h_to_b(t_stack *stack, t_input *input, t_parts *p);
#endif