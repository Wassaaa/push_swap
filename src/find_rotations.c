/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:35:59 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 01:46:00 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*node_at_index(t_list *list, int a_index)
{
	while (a_index--)
		list = list->next;
	return (list);
}

int	find_insert_spot(t_stack *stack, int b_index)
{
	t_list	*b_node;
	t_list	*current_a;
	t_list	*before;
	int		a_index;

	a_index = 0;
	before = ft_lstlast(stack->a_top);
	while (42)
	{
		b_node = node_at_index(stack->b_top, b_index);
		current_a = node_at_index(stack->a_top, a_index);
		if (*(int *)current_a->content < *(int *)b_node->content)
		{
			before = current_a;
			a_index++;
		}
		else if (*(int *)before->content > *(int *)b_node->content)
		{
			a_index++;
			before = current_a;
		}
		else
			return (a_index);
	}
}

void	get_rotations(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{
	ft_bzero(rot, sizeof(*rot) * 4);
	both_up(a_idx, b_idx, rot);
	both_down(stack, a_idx, b_idx, rot);
	up_down(stack, a_idx, b_idx, rot);
	down_up(stack, a_idx, b_idx, rot);
}

t_rot	best_rot(t_rot *rot, t_rot best)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (rot[i].cost < best.cost)
			best = rot[i];
		i++;
	}
	return (best);
}

t_rot	find_best_rotation(t_stack *stack, int b_index)
{
	int		a_index;
	t_rot	rot[4];
	t_rot	best;
	int		b_size;

	a_index = find_insert_spot(stack, b_index);
	get_rotations(stack, a_index, b_index, rot);
	best = rot[0];
	b_size = ft_lstsize(stack->b_top);
	while (++b_index < b_size)
	{
		best = best_rot(rot, best);
		if (best.cost <= GOOD_ENOUGH)
			return (best);
		a_index = find_insert_spot(stack, b_index);
		get_rotations(stack, a_index, b_index, rot);
	}
	return (best);
}
