/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_prints_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:29:17 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 01:23:54 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

static void	print_content(void *content)
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putchar_fd(' ', 1);
}

void	print_current_stacks(t_stack *stack)
{
	ft_putstr_fd("A_: ", 1);
	ft_lstiter(stack->a_top, print_content);
	ft_putstr_fd("\nB_: ", 1);
	ft_lstiter(stack->b_top, print_content);
	ft_putstr_fd("\n\n", 1);
}
