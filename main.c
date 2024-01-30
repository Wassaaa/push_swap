/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/01/30 20:20:08 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int *parse_numbers(t_input *input);

int main(int argc, char **argv)
{
	t_input input;
	int		i;

	i = 0;

	printf("%d\n", argc);
	printf("%s\n", argv[1]);

	input.args = argv[1];
	input.arr = parse_numbers(&input);
	while (i < input.nr_count)
		printf("%d\n", input.arr[i++]);
}

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

int	count_nrs(char *n_str)
{
	int	counter;

	counter = 0;
	while(*n_str)
	{
		if (!ft_isdigit(*n_str))
			counter++;
		n_str++;
	}
	return (counter + 1);
}

int *parse_numbers(t_input *input)
{
	int			i;
	int			*arr;
	char	*n_str;

	n_str = input->args;
	i = 0;
	input->nr_count = count_nrs(input->args);
	arr = malloc(input->nr_count * sizeof(int));
	if (!arr)
		return (NULL);
	while (input->nr_count > i)
	{
		if (ft_isdigit(*n_str))
		{
			arr[i] = ft_atoi(n_str);
			n_str += count_digits(arr[i]) + 1;
		}
		i++;
	}
	return (arr);
}