/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:51 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 19:04:24 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
