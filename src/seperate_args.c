/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:15:37 by aklein            #+#    #+#             */
/*   Updated: 2024/02/07 01:14:54 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	seperate_args(t_input *input, char **argv)
{
	int i;
	int nb;

	i = 0;
	while (i < input->nr_count)
	{
		if (!checks_before_atol(argv[i + 1], ft_strlen(argv[i + 1])))
			crash(FAIL, NULL, input);
		nb = ft_atol(argv[i + 1]);
		add_to_arrays(input, nb, &i);
		i++;
	}
}