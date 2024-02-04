/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:35:59 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:37:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*node_at_index(t_list *list, int a_index)
{
	while (a_index--)
		list = list->next;
	return (list);
}

static int	find_a_spot(t_stack *stack)
{
	int		a_top;
	int		b_top;
	int		a_bot;
	int		a_index;
	t_list	*current;

	b_top = *(int *)stack->b_top->content;
	a_bot = *(int *)ft_lstlast(stack->a_top)->content;
	a_index = 0;
	while (42)
	{
		current = node_at_index(stack->a_top, a_index);
		a_top = *(int *)current->content;
		if (a_top < b_top)
			{
				a_index++;
				a_bot = a_top;
				continue ;
			}
		if (a_top > b_top)
		{
			if (a_bot > b_top)
			{
				a_index++;
				a_bot = a_top;
				continue ;
			}
		}
		return (a_index);
	}
}

static void	get_rotations(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{

	ft_bzero(rot, sizeof(*rot) * 4);
	both_up(a_idx, b_idx, rot);
	both_down(stack, a_idx, b_idx, rot);
	up_down(stack, a_idx, b_idx, rot);
	down_up(stack, a_idx, b_idx, rot);

}

static t_rot	best_rot(t_rot *rot, t_rot best)
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

t_rot	find_best_rotation(t_stack *stack)
{
	int		a_index;
	int		b_index;
	t_rot	rot[4];
	t_rot	best;
	int		b_size;

	b_index = 0;
	a_index = find_a_spot(stack);
	get_rotations(stack, a_index, b_index, rot);
	best = rot[0];
	b_size = ft_lstsize(stack->b_top);
	while (b_index < b_size)
	{
		best = best_rot(rot, best);
		if (best.cost <= 1)
			return (best);
		b_index++;
		get_rotations(stack, a_index, b_index, rot);
	}
	return (best);
}

