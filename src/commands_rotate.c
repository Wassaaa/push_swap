/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:21:42 by aklein            #+#    #+#             */
/*   Updated: 2024/02/10 23:40:41 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ra(t_stack *stack, int print)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
		return (1);
	next = stack->a_top->next;
	plucked = pluck_first(&stack->a_top);
	stack->a_top = next;
	ft_lstadd_back(&stack->a_top, plucked);
	if (print)
		print_output(RA, stack);
	return (1);
}

int	rb(t_stack *stack, int print)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
		return (1);
	next = stack->b_top->next;
	plucked = pluck_first(&stack->b_top);
	stack->b_top = next;
	ft_lstadd_back(&stack->b_top, plucked);
	if (print)
		print_output(RB, stack);
	return (1);
}

int	rr(t_stack *stack, int print)
{
	ra(stack, 0);
	rb(stack, 0);
	if (print)
		print_output(RR, stack);
	return (1);
}
