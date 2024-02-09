/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_string_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:32:34 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 02:07:05 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	count_args(t_input *input)
{
	char	*str;

	str = input->args;
	input->nr_count = 0;
	while (*str)
	{
		while (ft_is_sign_or_digit(*str))
			str++;
		if (*str != ' ' && *str != '\0')
			crash(FAIL, NULL, input);
		if (*str != '\0')
			str++;
		input->nr_count++;
	}
	if (input->nr_count == 0)
		crash(FAIL, NULL, input);
}

void	single_arg(t_input *input)
{
	int		i;
	long	nb;
	char	*str;

	i = 0;
	str = input->args;
	while (i < input->nr_count)
	{
		while (ft_is_sign_or_digit(*str))
			str++;
		if (!checks_before_atol(input->args, str - input->args))
			crash(FAIL, NULL, input);
		str++;
		nb = ft_atol(input->args);
		add_to_arrays(input, nb, &i);
		input->args = str;
		i++;
	}
}
