/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:42:29 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:42:35 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_b_to_a(t_stack *stack, t_input *input)
{
	t_rot	best;

	while (stack->b_top != NULL)
	{
		best = find_best_rotation(stack);
		execute_best(best, stack);
		pa(stack);
		print_output(PA, stack);
	}
	finish_rotations(stack, input);
}

void	finish_rotations(t_stack *stack, t_input *input)
{
	int		i;
	int		a_n;
	t_rot	rot;
	t_list	*temp;

	i = 0;
	ft_bzero(&rot, sizeof(rot));
	a_n = ft_lstsize(stack->a_top);
	temp = stack->a_top;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content != input->control[0])
		{
			i++;
			temp = temp->next;
			continue ;
		}
		break ;
	}
	if (i > a_n - i)
		rot.rra = a_n - i;
	else
		rot.ra = i;
	execute_best(rot, stack);
}