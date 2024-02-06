/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:01 by aklein            #+#    #+#             */
/*   Updated: 2024/02/06 18:20:38 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	execute_best(t_rot best, t_stack *stack)
{
	while (best.ra--)
		ra(stack, 1);
	while (best.rb--)
		rb(stack, 1);
	while (best.rr--)
		rr(stack, 1);
	while (best.rra--)
		rra(stack, 1);
	while (best.rrb--)
		rrb(stack, 1);
	while (best.rrr--)
		rrr(stack, 1);
}
