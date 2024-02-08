/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:17:29 by aklein            #+#    #+#             */
/*   Updated: 2024/02/08 18:28:49 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_unique(t_input *input, int nb, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (input->arr[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	checks_before_atol(char *arg, int len)
{
	int	i;

	if (len > 11 || len < 1)
		return (0);
	if (len == 1 && (*arg == '+' || *arg == '-'))
		return (0);
	if (*arg == '-' && *(arg + 1) == '0')
		return (0);
	i = 0;
	while (i < len)
	{
		if (i == 0 && !ft_is_sign_or_digit(arg[i]))
			return (0);
		if (i > 0 && !ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sign_or_digit(char c)
{
	if (c == '+' || c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}
