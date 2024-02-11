/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:10:54 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 01:20:50 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	print_output(char *msg, t_stack *stack)
{
	ft_putendl_fd(msg, 1);
	if (SHOW_STACKS)
		print_current_stacks(stack);
}

t_list	*pluck_first(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	return (temp);
}

t_list	*pluck_last(t_list **lst)
{
	t_list	*temp;
	t_list	*new_last;

	temp = *lst;
	if (lst == NULL || *lst == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			new_last = temp;
		temp = temp->next;
	}
	new_last->next = NULL;
	return (temp);
}
