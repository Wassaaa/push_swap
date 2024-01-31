/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/01/31 20:51:26 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_stack
{
	t_list	*top;
}			t_stack;

typedef struct s_parts
{
	int		min;
	int		low_mid;
	int		mid;
	int		high_mid;
	int		max;
}			t_parts;

typedef struct s_input
{
	int		*arr;
	char	*args;
	int		nr_count;
}			t_input;

#endif