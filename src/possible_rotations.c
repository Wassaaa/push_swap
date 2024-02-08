/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:00:57 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 18:29:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_cost(t_rot *rot)
{
	rot->cost = rot->ra + rot->rb + rot->rr + rot->rra + rot->rrb + rot->rrr;
}

void	both_up(int a_idx, int b_idx, t_rot *rot)
{
	rot[0].ra = a_idx;
	rot[0].rb = b_idx;
	if (rot[0].rb > rot[0].ra)
		rot[0].rr = rot[0].ra;
	else
		rot[0].rr = rot[0].rb;
	rot[0].ra -= rot[0].rr;
	rot[0].rb -= rot[0].rr;
	set_cost(&rot[0]);
}

void	both_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{
	int	a_n;
	int	b_n;

	a_n = ft_lstsize(stack->a_top);
	b_n = ft_lstsize(stack->b_top);
	rot[1].rra = a_n - a_idx;
	rot[1].rrb = b_n - b_idx;
	if (rot[1].rrb > rot[1].rra)
		rot[1].rrr = rot[1].rra;
	else
		rot[1].rrr = rot[1].rrb;
	rot[1].rra -= rot[1].rrr;
	rot[1].rrb -= rot[1].rrr;
	set_cost(&rot[1]);
}

void	up_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{
	int	b_n;

	b_n = ft_lstsize(stack->b_top);
	rot[2].ra = a_idx;
	rot[2].rrb = b_n - b_idx;
	set_cost(&rot[2]);
}

void	down_up(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{
	int	a_n;

	a_n = ft_lstsize(stack->a_top);
	rot[3].rra = a_n - a_idx;
	rot[3].rb = b_idx;
	set_cost(&rot[3]);
}
