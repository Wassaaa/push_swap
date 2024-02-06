/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:59:16 by aklein            #+#    #+#             */
/*   Updated: 2024/02/07 01:35:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	validate_args(int argc, char **argv, t_input *input)
{
	if (argc < 2)
		crash(SUCCESS, NULL, input);
	if (argc > 2)
	{
		input->nr_count = argc - 1;
		seperate_args(input, argv);
	}
	else
	{
		input->args = argv[1];
		if (*input->args == '\0' || !ft_is_sign_or_digit(*input->args))
			crash(FAIL, NULL, input);
		count_args(input);
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
