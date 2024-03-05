/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:15:49 by aklein            #+#    #+#             */
/*   Updated: 2024/03/05 15:54:27 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_bonus.h>

void	construct_stack(t_input *input, t_stack *stack)
{
	int	i;

	ft_bzero(stack, sizeof(*stack));
	i = -1;
	stack->a_top = NULL;
	if (input->arr && input->nr_count > 0)
		while (++i < input->nr_count)
			ft_lstadd_back(&stack->a_top, ft_lstnew(&input->arr[i]));
}

static void	init_arrays(t_input *input)
{
	input->arr = ft_calloc(input->nr_count, sizeof(int));
	if (!input->arr)
		b_crash(FAIL, NULL, input);
}

void	validate_args(int argc, char **argv, t_input *input)
{
	input->arr = NULL;
	if (argc < 2)
		b_crash(NO_ARG, NULL, input);
	if (argc > 2)
	{
		input->nr_count = argc - 1;
		init_arrays(input);
		seperate_args(input, argv);
	}
	else
	{
		input->args = argv[1];
		count_args(input);
		init_arrays(input);
		single_arg(input);
	}
}

void	add_to_arrays(t_input *input, long nb, int *index)
{
	if (nb > INT_MAX || nb < INT_MIN)
		b_crash(FAIL, NULL, input);
	if (!is_unique(input, nb, *index))
		b_crash(FAIL, NULL, input);
	input->arr[*index] = (int)nb;
}
