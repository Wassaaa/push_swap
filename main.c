/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 19:04:55 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_input	input;
	t_stack	stack;
	t_parts	p;

	validate_args(argc, argv, &input);
	construct_stack(&input, &stack);
	find_parts(&p, &input);
	quick_sort(input.control, 0, input.nr_count - 1);
	if (is_sorted(stack.a_top))
		crash(SUCCESS, &stack, &input);
	if (input.nr_count <= 5)
	{
		handle_less(&stack, &input);
		crash(SUCCESS, &stack, &input);
	}
	push_l_to_b(&stack, &input, &p);
	push_h_to_b(&stack, &input, &p);
	handle_less(&stack, &input);
	push_b_to_a(&stack, &input);
	crash(SUCCESS, &stack, &input);
	return (0);
}
