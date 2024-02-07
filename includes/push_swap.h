/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/07 16:34:09 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define SHOW_STACKS 0

# define SUCCESS 0
# define FAIL 1

# define PB "pb"
# define PA "pa"

# define RA "ra"
# define RB "rb"
# define RR "rr"

# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# define SA "sa"
# define SB "sb"

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

typedef struct s_rot
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		cost;
}			t_rot;

/*INPUT CONTROL*/
void		seperate_args(t_input *input, char **argv);
void		count_args(t_input *input);
void		single_arg(t_input *input);
int			is_unique(t_input *input, int nb, int index);
int			checks_before_atol(char *arg, int len);
int			ft_is_sign_or_digit(char c);
long		ft_atol(const char *str);

void		init_arrays(t_input *input);
void		validate_args(int argc, char **argv, t_input *input);
void		add_to_arrays(t_input *input, long nb, int *index);

/*START*/
void		find_parts(t_parts *p, t_input *input);
void		quick_sort(int *arr, int start, int end);
void		construct_stack(t_input *input, t_stack *stack);
void		handle_less(t_stack *stack, t_input *input, t_parts *p);

/*PUSH TO B*/
void		pa(t_stack *stack, int print);
void		pb(t_stack *stack, int print);
void		ra(t_stack *stack, int print);
void		rb(t_stack *stack, int print);
void		rr(t_stack *stack, int print);
void		rra(t_stack *stack, int print);
void		rrb(t_stack *stack, int print);
void		rrr(t_stack *stack, int print);
void		sa(t_stack *stack, int print);
void		sb(t_stack *stack, int print);
int			is_sorted(t_list *list, int min);
void		sort_three(t_stack *stack, t_input *input, t_parts *p);
t_list		*pluck_first(t_list **lst);
void		push_l_to_b(t_stack *stack, t_input *input, t_parts *p);
void		push_h_to_b(t_stack *stack, t_input *input, t_parts *p);
void		push_b_to_a(t_stack *stack, t_input *input);

/*ROTATIONS*/
t_rot		find_best_rotation(t_stack *stack);
void		both_up(int a_idx, int b_idx, t_rot *rot);
void		both_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
void		up_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
void		down_up(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
void		set_cost(t_rot *rot);
void		execute_best(t_rot best, t_stack *stack);

/*OUTPUT*/
void		print_current_stacks(t_stack *stack);
void		print_output(char *msg, t_stack *stack);
void		crash(int err, t_stack *stack, t_input *input);
#endif
