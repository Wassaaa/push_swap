/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:58:32 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 01:46:15 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static char	*ft_skip_whitespace(char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

long	ft_atol(const char *str)
{
	long	number;
	long	prev;
	int		sign;

	number = 0;
	sign = 1;
	prev = 0;
	str = ft_skip_whitespace((char *)str);
	if (ft_is_sign(*str))
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str++ - '0');
		if (prev > number)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		prev = number;
	}
	return ((long)(number * sign));
}
