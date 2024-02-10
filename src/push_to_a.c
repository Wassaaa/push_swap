/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:42:29 by aklein            #+#    #+#             */
/*   Updated: 2024/02/10 22:26:06 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_rot	final_rot(t_stack *stack, t_input *input)
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
	rot.cost = rot.rra + rot.ra;
	return (rot);
}

void	fix_sim_len(t_input *input)
{
	if (input->sim_len > SIM_LEN)
		input->sim_len = SIM_LEN;
	else
		input->sim_len++;
}

void	setup_imod(t_input *input)
{
	input->i_mod = INDEX_MOD;
	if (input->nr_count / 6 > input->i_mod)
		input->i_mod = input->nr_count / 6;
}

void	push_b_to_a(t_stack *stack, t_input *input)
{
	t_rot	*my_moves;
	int		i;

	input->sim_len = ft_lstsize(stack->b_top);
	input->b_counter = input->sim_len;
	input->best_cost = INT_MAX;
	while (input->b_counter > 0)
	{
		fix_sim_len(input);
		my_moves = evaluate_moves(stack, input);
		i = 0;
		while (i < input->sim_len)
		{
			exec(my_moves[i], stack, 1);
			pa(stack, 1);
			i++;
		}
		free(my_moves);
		my_moves = NULL;
		input->b_counter -= input->sim_len;
		input->sim_len = input->b_counter;
	}
}

void	b_to_a_high(t_stack *stack, t_input *input)
{
	t_rot	best;

	while (stack->b_top != NULL)
	{
		best = find_best_rotation(stack, 0);
		exec(best, stack, 1);
		pa(stack, 1);
	}
	exec(final_rot(stack, input), stack, 1);
}
