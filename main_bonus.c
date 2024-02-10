/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:58:55 by aklein            #+#    #+#             */
/*   Updated: 2024/02/10 23:39:42 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	main(int argc, char **argv)
{
	t_input	input;
	t_stack	stack;

	validate_args(argc, argv, &input);
	construct_stack(&input, &stack);
	return (0);
}

int	exec_command(char *str, t_stack *stack)
{
	if (!ft_strncmp(str, "ra\n", 3))
		return (ra(stack, 1));
	if (!ft_strncmp(str, "rb\n", 3))
		return (rb(stack, 1));
	if (!ft_strncmp(str, "rr\n", 3))
		return (rr(stack, 1));
	if (!ft_strncmp(str, "rra\n", 4))
		return (rra(stack, 1));
	if (!ft_strncmp(str, "rrb\n", 4))
		return (rrb(stack, 1));
	if (!ft_strncmp(str, "rrr\n", 4))
		return (rrr(stack, 1));
	if (!ft_strncmp(str, "pa\n", 3))
		return (pa(stack, 1));
	if (!ft_strncmp(str, "pb\n", 3))
		return (pb(stack, 1));
	if (!ft_strncmp(str, "sa\n", 3))
		return (sa(stack, 1));
	if (!ft_strncmp(str, "sb\n", 3))
		return (sb(stack, 1));
	if (!ft_strncmp(str, "ss\n", 3))
		return (ss(stack, 1));
	return (0);
}

int	read_and_exec(t_stack *stack)
{
	char	*line;

	line = get_next_line(1);
	while (line != NULL)
	{
		if (!exec_command(line, stack))
			b_crash();

	}
}
