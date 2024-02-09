/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:39:11 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 21:51:20 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_parts(t_parts *p, t_input *input)
{
	p->min = 0;
	p->second = 1;
	p->third = 2;
	p->low_mid = (input->nr_count) / 5;
	p->mid = input->nr_count / 2;
	p->high_mid = (input->nr_count) * 3 / 4;
	p->max = input->nr_count - 1;
}

t_list	*find_max(t_list *a)
{
	int		max;
	t_list	*max_node;

	max = INT_MIN;
	while (a)
	{
		if (*(int *)a->content > max)
		{
			max = *(int *)a->content;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

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
