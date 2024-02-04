/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:51 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:43:59 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_list *list, int min)
{
	int	current;

	if (*(int *)list->content != min)
		return (0);
	current = min;
	while (list && list->next != NULL)
	{
		if (*(int *)list->next->content > current)
			current = *(int *)list->next->content;
		else
			return (0);
		list = list->next;
	}
	return (1);
}