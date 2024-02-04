/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:59:16 by aklein            #+#    #+#             */
/*   Updated: 2024/02/05 00:19:49 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <limits.h>

int	is_unique(t_input *input, int nb, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (input->arr[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

static void	arg_per_nr(int argc, char **argv, t_input *input)
{
	int		i;
	long	nb;

	input->nr_count = argc - 1;
	input->arr = ft_calloc(input->nr_count, sizeof(int));
	input->control = ft_calloc(input->nr_count, sizeof(int));
		i = 0;
	while (i < input->nr_count)
	{
		if (ft_strlen(argv[i + 1]) > 11)
			crash(FAIL);
		nb = ft_atol(argv[i + 1]);
		if (nb > INT_MAX || nb < INT_MIN)
			crash(FAIL);
		if (!is_unique(input, nb, i))
			crash(FAIL);
		input->arr[i] = (int)nb;
		input->control[i] = (int)nb;
		i++;
	}

}

void	validate_args(int argc, char **argv, t_input *input)
{
	if (argc < 2)
		crash(FAIL);
	if (argc > 2)
		arg_per_nr(argc, argv, input);
	else
	{
		input->args = argv[1];
		one_arg(input);
	}
}
