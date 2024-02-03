/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 02:54:08 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_stack
{
	t_list	*a_top;
	t_list	*b_top;
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
	int		*control;
	int		nr_count;
}			t_input;

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	pb(t_stack *stack);
void	sb(t_stack *stack);
t_list	*pluck_first(t_list **lst);
void push_to_b(t_stack *stack, t_input *input, t_parts *p);
#endif