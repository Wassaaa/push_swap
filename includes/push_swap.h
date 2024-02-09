/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/02/09 22:54:41 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>

# define SHOW_STACKS 0
# define SIM_LEN 120
# define GOOD_ENOUGH 3
# define MAX_CRAZY_MODE 120

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
	int		second;
	int		third;
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
	int		current_cost;
	int		best_cost;
	int		b_n;
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

typedef struct s_rot_list
{
	t_rot	*best;
	t_rot	*new;
}			t_rot_list;

/*INPUT CONTROL*/
void		seperate_args(t_input *input, char **argv);
void		count_args(t_input *input);
void		single_arg(t_input *input);
int			is_unique(t_input *input, int nb, int index);
int			checks_before_atol(char *arg, int len);
int			ft_is_sign_or_digit(char c);
long		ft_atol(const char *str);
void		validate_args(int argc, char **argv, t_input *input);
void		add_to_arrays(t_input *input, long nb, int *index);

/*START*/
void		find_parts(t_parts *p, t_input *input);
void		quick_sort(int *arr, int start, int end);
void		construct_stack(t_input *input, t_stack *stack);
void		handle_less(t_stack *stack, t_input *input);
t_list		*find_max(t_list *a);
int			find_min(t_list *list);

/*PUSH TO B TO A*/
void		pa(t_stack *stack, int print);
void		pb(t_stack *stack, int print);
void		ra(t_stack *stack, int print);
void		rb(t_stack *stack, int print);
void		rr(t_stack *stack, int print);
void		rra(t_stack *stack, int print);
void		rrb(t_stack *stack, int print);
void		rrr(t_stack *stack, int print);
void		sa(t_stack *stack, int print);
int			is_sorted(t_list *stack);
void		sort_three(t_stack *stack);
t_list		*pluck_first(t_list **lst);
t_list		*pluck_last(t_list **lst);
void		push_l_to_b(t_stack *stack, t_input *input, t_parts *p);
void		push_h_to_b(t_stack *stack, t_input *input, t_parts *p);
void		push_b_to_a(t_stack *stack, t_input *input);
void		b_to_a_high(t_stack *stack, t_input *input);
void		free_stack(t_stack *stack);
void		del(void *content);

/*SIM*/
t_rot		*evaluate_moves(t_stack *stack, t_input *input);

/*ROTATIONS*/
t_rot		find_best_rotation(t_stack *stack, int b_index);
void		both_up(int a_idx, int b_idx, t_rot *rot);
void		both_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
void		up_down(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
void		down_up(t_stack *stack, int a_idx, int b_idx, t_rot *rot);
t_rot		final_rot(t_stack *stack, t_input *input);
void		exec(t_rot best, t_stack *stack, int print);

/*OUTPUT*/
void		print_current_stacks(t_stack *stack);
void		print_output(char *msg, t_stack *stack);
void		crash(int err, t_stack *stack, t_input *input);
#endif
