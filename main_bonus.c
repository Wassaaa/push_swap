/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:58:55 by aklein            #+#    #+#             */
/*   Updated: 2024/02/11 02:58:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

int	main(int argc, char **argv)
{
	t_input	input;
	t_stack	stack;

	validate_args(argc, argv, &input);
	construct_stack(&input, &stack);
	read_and_exec(&stack, &input);
	return (0);
}

int	exec_command(char *str, t_stack *stack)
{
	if (!ft_strncmp(str, "ra\n", 3))
		return (ra(stack, 0));
	if (!ft_strncmp(str, "rb\n", 3))
		return (rb(stack, 0));
	if (!ft_strncmp(str, "rr\n", 3))
		return (rr(stack, 0));
	if (!ft_strncmp(str, "rra\n", 4))
		return (rra(stack, 0));
	if (!ft_strncmp(str, "rrb\n", 4))
		return (rrb(stack, 0));
	if (!ft_strncmp(str, "rrr\n", 4))
		return (rrr(stack, 0));
	if (!ft_strncmp(str, "pa\n", 3))
		return (pa(stack, 0));
	if (!ft_strncmp(str, "pb\n", 3))
		return (pb(stack, 0));
	if (!ft_strncmp(str, "sa\n", 3))
		return (sa(stack, 0));
	if (!ft_strncmp(str, "sb\n", 3))
		return (sb(stack, 0));
	if (!ft_strncmp(str, "ss\n", 3))
		return (ss(stack, 0));
	return (0);
}

void	del(void *content)
{
	if (content)
		content = NULL;
}

void b_crash(int err, t_stack *stack, t_input *input)
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
	if (err == FAIL)
		ft_putendl_fd("Error", 2);
	if (err == SUCCESS)
		ft_putendl_fd("OK", 1);
	if (err == NOT_SORTED)
	{
		ft_putendl_fd("KO", 1);
		err = SUCCESS;
	}
	exit(err);
}

void	read_and_exec(t_stack *stack, t_input *input)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!exec_command(line, stack))
			b_crash(FAIL, stack, input);
		line = get_next_line(0);
	}
	if (is_sorted(stack->a_top))
		b_crash(SUCCESS, stack, input);
	b_crash(NOT_SORTED, stack, input);
}
