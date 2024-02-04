/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:34:33 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 18:34:46 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_output(char *msg, t_stack *stack)
{
	ft_putendl_fd(msg, 1);
	if (SHOW_STACKS)
		print_current_stacks(stack);
}