/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:39:56 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 22:04:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_breakpoint(int content, t_parts *p, t_input *input)
{
	if (content == input->control[p->min])
		return (1);
	if (content == input->control[p->second])
		return (1);
	if (content == input->control[p->third])
		return (1);
	if (content == input->control[p->mid])
		return (1);
	if (content == input->control[p->max])
		return (1);
	return (0);
}

void	push_l_to_b(t_stack *stack, t_input *inp, t_parts *p)
{
	int	a_top;
	int	stop_target;
	int	len;

	len = ft_lstsize(stack->a_top);
	stop_target = p->max - p->high_mid + 4;
	while (len > stop_target)
	{
		a_top = *(int *)stack->a_top->content;
		if (is_breakpoint(a_top, p, inp) || a_top > inp->control[p->high_mid])
		{
			ra(stack, 1);
			continue ;
		}
		pb(stack, 1);
		len--;
		if (a_top < inp->control[p->low_mid])
		{
			rb(stack, 1);
		}
	}
}

void	push_h_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	int	a_int_top;
	int	len;

	len = ft_lstsize(stack->a_top);
	while (len > 5)
	{
		a_int_top = *(int *)stack->a_top->content;
		if (is_breakpoint(a_int_top, p, input))
		{
			ra(stack, 1);
			continue ;
		}
		pb(stack, 1);
		len--;
	}
}
