/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:59:16 by aklein            #+#    #+#             */
/*   Updated: 2024/02/07 02:58:21 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	init_input(t_input *input)
{
	input->arr = NULL;
	input->control = NULL;
}

void	validate_args(int argc, char **argv, t_input *input)
{
	init_input(input);
	if (argc < 2)
		crash(SUCCESS, NULL, input);
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

void	init_arrays(t_input *input)
{
	input->arr = ft_calloc(input->nr_count, sizeof(int));
	input->control = ft_calloc(input->nr_count, sizeof(int));
	if (!input->arr || !input->control)
		crash(FAIL, NULL, input);
}

void	add_to_arrays(t_input *input, long nb, int *index)
{
	if (nb > INT_MAX || nb < INT_MIN)
		crash(FAIL, NULL, input);
	if (!is_unique(input, nb, *index))
		crash(FAIL, NULL, input);
	input->arr[*index] = (int)nb;
	input->control[*index] = (int)nb;
}
