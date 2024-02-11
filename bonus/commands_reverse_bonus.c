/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:22:52 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 01:15:36 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	rra(t_stack *stack, int print)
{
	t_list	*plucked;

	if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
		return (1);
	plucked = pluck_last(&stack->a_top);
	ft_lstadd_front(&stack->a_top, plucked);
	if (print)
		print_output(RRA, stack);
	return (1);
}

int	rrb(t_stack *stack, int print)
{
	t_list	*plucked;

	if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
		return (1);
	plucked = pluck_last(&stack->b_top);
	ft_lstadd_front(&stack->b_top, plucked);
	if (print)
		print_output(RRB, stack);
	return (1);
}

int	rrr(t_stack *stack, int print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (print)
		print_output(RRR, stack);
	return (1);
}
