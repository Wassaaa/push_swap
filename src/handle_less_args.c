/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_less_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:19:28 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 01:06:50 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_min(t_list *list)
{
	int	min;

	min = INT_MAX;
	while (list != NULL)
	{
		if (*(int *)list->content < min)
			min = *(int *)list->content;
		list = list->next;
	}
	return (min);
}

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

void	handle_less(t_stack *stack, t_input *input, t_parts *p)
{
	int		index;
	int		a_n;
	t_rot	rot;

	if (input->nr_count <= 3)
		sort_three(stack, input, p);
	else
	{
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
		sort_three(stack, input, p);
		pa(stack, 1);
		pa(stack, 1);
	}
	crash(SUCCESS, stack, input);
}
