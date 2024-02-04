/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_string_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:32:34 by aklein            #+#    #+#             */
/*   Updated: 2024/02/04 20:18:36 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static size_t	count_digits(int n)
{
	size_t	digits;

	digits = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int	count_nrs(char *n_str)
{
	int	counter;

	counter = 0;
	if (*n_str == '\0')
		return (0);
	while(*n_str)
	{
		if (!ft_isdigit(*n_str))
			counter++;
		n_str++;
	}
	return (counter + 1);
}

void parse_numbers(t_input *input)
{
	int			i;
	int			*arr;
	int			*control;
	char		*n_str;

	n_str = input->args;
	i = 0;
	input->nr_count = count_nrs(input->args);
	arr = ft_calloc(input->nr_count, sizeof(int));
	control = ft_calloc(input->nr_count, sizeof(int));
	if (!arr || !control)
		crash(FAIL);
	while (input->nr_count > i)
	{
		if (ft_isdigit(*n_str))
		{
			arr[i] = ft_atoi(n_str);
			control[i] = ft_atoi(n_str);
			n_str += count_digits(arr[i]) + 1;
		}
		i++;
	}
	input->control = control;
	input->arr = arr;
}