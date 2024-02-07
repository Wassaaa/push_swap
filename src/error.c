/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:57:55 by aklein            #+#    #+#             */
/*   Updated: 2024/02/07 16:32:27 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	del(void *content)
{
	if (content)
		content = NULL;
}

void	crash(int err, t_stack *stack, t_input *input)
{
	if (stack && stack->a_top)
		ft_lstclear(&stack->a_top, del);
	if (stack && stack->b_top)
		ft_lstclear(&stack->b_top, del);
	if (input->arr != NULL)
	{
		free(input->arr);
		input->arr = NULL;
	}
	if (input->control != NULL)
	{
		free(input->control);
		input->control = NULL;
	}
	if (err == FAIL)
		ft_putendl_fd("Error", 2);
	exit(err);
}
