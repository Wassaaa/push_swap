/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:39:56 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 20:43:13 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_breakpoint(int content, t_parts *p, t_input *input)
{
	if (content == input->control[p->min])
		return (1);
	if (content == input->control[p->mid])
		return (1);
	if (content == input->control[p->max])
		return (1);
	return (0);
}

void	push_l_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	int	a_top_int;

	while (ft_lstsize(stack->a_top) > p->max - p->high_mid + 2)
	{
		a_top_int = *(int *)stack->a_top->content;
		if (is_breakpoint(a_top_int, p, input) || a_top_int > input->control[p->high_mid])
		{
			ra(stack, 1);
			continue ;
		}
		pb(stack, 1);
		if (a_top_int < input->control[p->low_mid])
		{

			sb(stack, 1);
		}

	}
}

void	push_h_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	while (ft_lstsize(stack->a_top) > 3)
	{
		int	a_int_top;

		a_int_top = *(int *)stack->a_top->content;
		if (is_breakpoint(a_int_top, p, input))
		{
			ra(stack, 1);
			continue ;
		}
		pb(stack, 1);
	}
}

void	sort_three(t_stack *stack, t_input *input, t_parts *p)
{
	int		first;
	int		second;

	if (is_sorted(stack->a_top, input->control[p->min]))
		return ;
	first = *(int *)stack->a_top->content;
	second = *(int *)stack->a_top->next->content;
	if (first == input->control[p->max])
		ra(stack, 1);
	else if (second == input->control[p->max])
		rra(stack, 1);
	first = *(int *)stack->a_top->content;
	second = *(int *)stack->a_top->next->content;
	if (first < second)
		return ;
	sa(stack, 1);
}