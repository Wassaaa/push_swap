/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_less_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:19:28 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 21:01:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_index(int nb, t_list *list)
{
	int	index;

	index = 0;
	while (list->next != NULL)
	{
		if (*(int *)list->content != nb)
		{
			index++;
			list = list->next;
			continue ;
		}
		break ;
	}
	return (index);
}

void	sort_three(t_stack *stack)
{
	t_list	*max_node;

	max_node = find_max(stack->a_top);
	if (stack->a_top == max_node)
		ra(stack, 1);
	else if (stack->a_top->next == max_node)
		rra(stack, 1);
	if (*(int *)stack->a_top->content > *(int *)stack->a_top->next->content)
		sa(stack, 1);
}

void	sort_five(t_stack *stack)
{
	int		index;
	int		start_len;
	int		a_n;
	t_rot	rot;

	start_len = ft_lstsize(stack->a_top);
	while (ft_lstsize(stack->a_top) > 3)
	{
		ft_bzero(&rot, sizeof(rot));
		a_n = ft_lstsize(stack->a_top);
		index = get_index(find_min(stack->a_top), stack->a_top);
		if (index > a_n - index)
			rot.rra = a_n - index;
		else
			rot.ra = index;
		exec(rot, stack, 1);
		pb(stack, 1);
	}
	sort_three(stack);
	pa(stack, 1);
	if (start_len == 5)
		pa(stack, 1);
}

void	handle_less(t_stack *stack, t_input *input)
{
	if (is_sorted(stack->a_top))
		return ;
	if (input->nr_count <= 3)
		sort_three(stack);
	else
		sort_five(stack);
}
