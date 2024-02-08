/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:22:52 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 18:28:37 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_stack *stack, int print)
{
	t_list	*plucked;

	if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
		return ;
	plucked = pluck_last(&stack->a_top);
	ft_lstadd_front(&stack->a_top, plucked);
	if (print)
		print_output(RRA, stack);
}

void	rrb(t_stack *stack, int print)
{
	t_list	*plucked;

	if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
		return ;
	plucked = pluck_last(&stack->b_top);
	ft_lstadd_front(&stack->b_top, plucked);
	if (print)
		print_output(RRB, stack);
}

void	rrr(t_stack *stack, int print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (print)
		print_output(RRR, stack);
}
