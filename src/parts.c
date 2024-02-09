/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:39:11 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 19:23:00 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_parts(t_parts *p, t_input *input)
{
	p->min = 0;
	p->low_mid = (input->nr_count) / 4;
	p->mid = input->nr_count / 2;
	p->high_mid = (input->nr_count) * 3 / 4;
	p->max = input->nr_count - 1;
	p->max1 = input->nr_count - 2;
	p->max2 = input->nr_count - 3;
}
