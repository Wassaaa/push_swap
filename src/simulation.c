/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:34:28 by aklein            #+#    #+#             */
/*   Updated: 2024/02/10 19:45:02 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack	*copy_stack(const t_stack *stack)
{
	t_stack	*new_stack;
	t_list	*current_a;
	t_list	*current_b;

	new_stack = ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	current_a = stack->a_top;
	while (current_a != NULL)
	{
		ft_lstadd_back(&new_stack->a_top, ft_lstnew(current_a->content));
		current_a = current_a->next;
	}
	current_b = stack->b_top;
	while (current_b != NULL)
	{
		ft_lstadd_back(&new_stack->b_top, ft_lstnew(current_b->content));
		current_b = current_b->next;
	}
	return (new_stack);
}

static int	add_to_rot(t_rot *r, t_rot best, int *i)
{
	r[*i] = best;
	*i = *i + 1;
	return (best.cost);
}

static void	ten_moves_ahead(t_stack *stack, int b_index, t_input *in, t_rot *r)
{
	t_stack	*current;
	t_rot	best;
	int		i;

	i = 0;
	in->current_cost = 0;
	current = copy_stack(stack);
	if (!current)
		crash(FAIL, stack, in);
	best = find_best_rotation(current, b_index, in->i_mod);
	exec(best, current, 0);
	pa(current, 0);
	in->current_cost += add_to_rot(r, best, &i);
	while (current->b_top != NULL && i < in->sim_len)
	{
		best = find_best_rotation(current, 0, in->i_mod);
		in->current_cost += add_to_rot(r, best, &i);
		exec(best, current, 0);
		pa(current, 0);
	}
	if (current->b_top == NULL)
		in->current_cost += add_to_rot(r, final_rot(current, in), &i);
	free_stack(current);
}

static void	update_best(t_rot_list *rots, t_input *input)
{
	if (input->current_cost < input->best_cost)
	{
		free(rots->best);
		rots->best = rots->new;
		input->best_cost = input->current_cost;
		rots->new = NULL;
	}
	free(rots->new);
	rots->new = NULL;
}

t_rot	*evaluate_moves(t_stack *stack, t_input *input)
{
	t_list		*current_b;
	int			index;
	t_rot_list	rots;

	current_b = stack->b_top;
	index = 0;
	rots.best = ft_calloc(input->sim_len, sizeof(t_rot));
	if (!rots.best)
		crash(FAIL, stack, input);
	while (current_b != NULL)
	{
		if (index < input->i_mod || index > input->b_counter - input->i_mod)
		{
			rots.new = ft_calloc(input->sim_len, sizeof(t_rot));
			if (!rots.new)
				crash(FAIL, stack, input);
			ten_moves_ahead(stack, index, input, rots.new);
			update_best(&rots, input);
		}
		current_b = current_b->next;
		index++;
	}
	return (rots.best);
}
