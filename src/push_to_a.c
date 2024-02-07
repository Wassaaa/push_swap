/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:42:29 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 01:07:47 by aklein           ###   ########.fr       */
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

int	ten_moves_ahead(t_stack *stack, int b_index, t_input *input)
{
	t_stack	*current;
	int		ten_cost;
	t_rot	best;

	ten_cost = 0;
	current = copy_stack(stack);
	if (!current)
		crash(FAIL, stack, input);
	best = find_best_rotation(current, b_index);
	exec(best, current, 0);
	ten_cost += best.cost;
	while (current->b_top != NULL)
	{
		best = find_best_rotation(current, 0);
		ten_cost += best.cost + 1;
		exec(best, current, 0);
		pa(current, 0);
	}
	if (current->b_top == NULL)
		ten_cost += final_rot(current, input).cost;
	free_stack(current);
	return (ten_cost);
}

int	evaluate_moves(t_stack *stack, t_input *input)
{
	int		lowest_cost;
	int		best_move_index;
	int		temp_cost;
	t_list	*current_b;
	int		index;

	lowest_cost = INT_MAX;
	best_move_index = -1;
	current_b = stack->b_top;
	index = 0;
	while (current_b != NULL)
	{
		temp_cost = ten_moves_ahead(stack, index, input);
		if (temp_cost < lowest_cost)
		{
			lowest_cost = temp_cost;
			best_move_index = index;
		}
		current_b = current_b->next;
		index++;
	}
	return (best_move_index);
}

void	push_b_to_a(t_stack *stack, t_input *input)
{
	t_rot	rot;
	int		best_index;

	while (stack->b_top != NULL)
	{
		best_index = evaluate_moves(stack, input);
		rot = find_best_rotation(stack, best_index);
		exec(rot, stack, 1);
		pa(stack, 1);
	}
	rot = final_rot(stack, input);
	exec(rot, stack, 1);
}
