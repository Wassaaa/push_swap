/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:16 by aklein            #+#    #+#             */
/*   Updated: 2024/02/06 17:49:35 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack *construct_stack(t_input *input)
{
	t_stack *stack;
	int		i;

	i = -1;
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		crash(FAIL, stack, input);
	stack->a_top = NULL;
	if (input->arr && input->nr_count > 0)
		while (++i < input->nr_count)
			ft_lstadd_back(&stack->a_top, ft_lstnew(&input->arr[i]));
	return (stack);
}