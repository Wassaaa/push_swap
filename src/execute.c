/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:01 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:43:08 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	execute_best(t_rot best, t_stack *stack)
{
	while (best.ra--)
	{
		ra(stack);
		print_output(RA, stack);
	}
	while (best.rb--)
	{
		rb(stack);
		print_output(RB, stack);
	}
	while (best.rr--)
	{
		rr(stack);
		print_output(RR, stack);
	}
	best_reverse(best, stack);
}

void	best_reverse(t_rot best, t_stack *stack)
{
	while (best.rra--)
	{
		rra(stack);
		print_output(RRA, stack);
	}
	while (best.rrb--)
	{
		rrb(stack);
		print_output(RRB, stack);
	}
	while (best.rrr--)
	{
		rrr(stack);
		print_output(RRR, stack);
	}
}