/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_string_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:32:34 by aklein            #+#    #+#             */
/*   Updated: 2024/02/05 21:30:27 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	count_digits(int n)
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

static int	minus_to_digit(char *str)
{
	if (*str == '-')
	{
		if (ft_isdigit(*(str + 1)))
			return (1);
		else
			return (0);
	}
	return (0);
}

void	validate_format(char *str, t_input *input)
{
	int	number_length;
	int	nr_count;

	nr_count = 0;
	while (*str)
	{
		number_length = 0;
		if (minus_to_digit(str))
			str++;
		if (!ft_isdigit(*str))
			crash(FAIL);
		while (ft_isdigit(*str))
		{
			number_length++;
			if (number_length > 11)
				crash(FAIL);
			str++;
		}
		if (*str != ' ' && *str != '\0')
			crash(FAIL);
		if (*str != '\0')
			str++;
		nr_count++;
	}
	input->nr_count = nr_count;
}

void	one_arg(t_input *input)
{
	validate_format(input->args, input);
	parse_numbers(input);
}

void	parse_numbers(t_input *input)
{
	int		i;
	char	*n_str;
	long	nb;

	i = 0;
	n_str = input->args;
	input->arr = ft_calloc(input->nr_count, sizeof(int));
	input->control = ft_calloc(input->nr_count, sizeof(int));
	if (!input->arr || !input->control)
		crash(FAIL);
	while (input->nr_count > i)
	{
		nb = ft_atol(n_str);
		if (nb > INT_MAX || nb < INT_MIN)
			crash(FAIL);
		if (!is_unique(input, nb, i))
			crash(FAIL);
		input->arr[i] = nb;
		input->control[i] = nb;
		n_str += count_digits(input->arr[i]) + 1;
		i++;
	}
}
