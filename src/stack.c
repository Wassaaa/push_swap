/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:16 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 02:05:03 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	construct_stack(t_input *input, t_stack *stack)
{
	int	i;

	ft_bzero(stack, sizeof(*stack));
	i = -1;
	stack->a_top = NULL;
	if (input->arr && input->nr_count > 0)
		while (++i < input->nr_count)
			ft_lstadd_back(&stack->a_top, ft_lstnew(&input->arr[i]));
}
