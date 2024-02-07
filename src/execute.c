/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:01 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 01:06:50 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec(t_rot best, t_stack *stack, int print)
{
	while (best.ra--)
		ra(stack, print);
	while (best.rb--)
		rb(stack, print);
	while (best.rr--)
		rr(stack, print);
	while (best.rra--)
		rra(stack, print);
	while (best.rrb--)
		rrb(stack, print);
	while (best.rrr--)
		rrr(stack, print);
}
