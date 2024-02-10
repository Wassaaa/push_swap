/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:23:28 by aklein            #+#    #+#             */
/*   Updated: 2024/02/10 23:44:55 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	pb(t_stack *stack, int print)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->a_top == NULL)
		return (1) ;
	next = stack->a_top->next;
	plucked = pluck_first(&stack->a_top);
	stack->a_top = next;
	ft_lstadd_front(&stack->b_top, plucked);
	stack->b_top = plucked;
	if (print)
		print_output(PB, stack);
	return (1);
}

int	pa(t_stack *stack, int print)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->b_top == NULL)
		return (1) ;
	next = stack->b_top->next;
	plucked = pluck_first(&stack->b_top);
	stack->b_top = next;
	ft_lstadd_front(&stack->a_top, plucked);
	stack->a_top = plucked;
	if (print)
		print_output(PA, stack);
	return (1);
}

int	sa(t_stack *stack, int print)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->a_top == NULL)
		return (1) ;
	if (stack->a_top->next == NULL)
		return (1) ;
	first = pluck_first(&stack->a_top);
	second = pluck_first(&stack->a_top);
	ft_lstadd_front(&stack->a_top, first);
	ft_lstadd_front(&stack->a_top, second);
	if (print)
		print_output(SA, stack);
	return (1);
}

int	sb(t_stack *stack, int print)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->b_top == NULL)
		return (1) ;
	if (stack->b_top->next == NULL)
		return (1) ;
	first = pluck_first(&stack->b_top);
	second = pluck_first(&stack->b_top);
	ft_lstadd_front(&stack->b_top, first);
	ft_lstadd_front(&stack->b_top, second);
	if (print)
		print_output(SB, stack);
	return (1);
}

int	ss(t_stack *stack, int print)
{
	sa(stack, 0);
	sb(stack, 0);
	if (print)
		print_output(SB, stack);
	return (1);
}
