/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:42:29 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 01:22:45 by aklein           ###   ########.fr       */
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
	return (rot);
}

void	del_free(void *content)
{
	if (content)
	{
		content = NULL;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack && stack->a_top)
		ft_lstclear(&stack->a_top, del_free);
	if (stack && stack->b_top)
		ft_lstclear(&stack->b_top, del_free);
	if (stack)
		free(stack);
}

t_stack	*copy_stack(const t_stack *stack)
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

int	add_to_rot(t_rot *r, t_rot best, int *i)
{
	r[*i] = best;
	*i = *i + 1;
	return (best.cost);
}

void	ten_moves_ahead(t_stack *stack, int b_index, t_input *input, t_rot *r)
{
	t_stack	*current;
	t_rot	best;
	int		i;

	i = 0;
	input->current_cost = 0;
	current = copy_stack(stack);
	if (!current)
		crash(FAIL, stack, input);
	best = find_best_rotation(current, b_index);
	exec(best, current, 0);
	pa(current, 0);
	input->current_cost += add_to_rot(r, best, &i);
	while (current->b_top != NULL && i < input->b_n)
	{
		best = find_best_rotation(current, 0);
		input->current_cost += add_to_rot(r, best, &i);
		exec(best, current, 0);
		pa(current, 0);
	}
	if (current->b_top == NULL)
		input->current_cost += add_to_rot(r, final_rot(current, input), &i);
	free_stack(current);
}

void	update_best(t_rot_list *rots, t_input *input)
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
	rots.best = ft_calloc(input->b_n, sizeof(t_rot));
	if (!rots.best)
		crash(FAIL, stack, input);
	while (current_b != NULL)
	{
		rots.new = ft_calloc(input->b_n, sizeof(t_rot));
		if (!rots.new)
			crash(FAIL, stack, input);
		ten_moves_ahead(stack, index, input, rots.new);
		update_best(&rots, input);
		current_b = current_b->next;
		index++;
	}
	return (rots.best);
}

void	push_b_to_a(t_stack *stack, t_input *input)
{
	t_rot	*my_moves;
	int		i;

	while (stack->b_top != NULL)
	{
		input->best_cost = INT_MAX;
		input->b_n = ft_lstsize(stack->b_top);
		if (input->b_n > SIM_LEN)
			input->b_n = SIM_LEN;
		else
			input->b_n++;
		my_moves = evaluate_moves(stack, input);
		i = 0;
		while (i < input->b_n)
		{
			exec(my_moves[i], stack, 1);
			pa(stack, 1);
			i++;
		}
		free(my_moves);
		my_moves = NULL;
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
