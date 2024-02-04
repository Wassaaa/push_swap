/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:50:44 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_input	input;
	t_stack	*stack;
	t_parts	p;

	validate_args(argc, argv, &input);
	stack = construct_stack(&input);
	find_parts(&p, &input);
	quick_sort(input.control, 0, input.nr_count - 1);
	if (is_sorted(stack->a_top, input.control[p.min]))
		return (0);
	push_l_to_b(stack, &input, &p);
	push_h_to_b(stack, &input, &p);
	sort_bps(stack, &input, &p);
	push_b_to_a(stack, &input);
}
