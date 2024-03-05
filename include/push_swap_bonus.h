/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:31:10 by aklein            #+#    #+#             */
/*   Updated: 2024/03/05 16:20:49 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <libft.h>

# define SUCCESS 0
# define FAIL 1
# define NOT_SORTED 2
# define NO_ARG 3
# define SHOW_STACKS 0

# define INT_MIN -2147483648
# define INT_MAX 2147483647

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

typedef struct s_input
{
	int		*arr;
	char	*args;
	int		nr_count;
}			t_input;

/*INPUT CONTROL*/
void		validate_args(int argc, char **argv, t_input *input);
void		seperate_args(t_input *input, char **argv);
void		count_args(t_input *input);
void		single_arg(t_input *input);
int			is_unique(t_input *input, int nb, int index);
int			checks_before_atol(char *arg, int len);
int			ft_is_sign_or_digit(char c);
long		ft_atol(const char *str);
void		add_to_arrays(t_input *input, long nb, int *index);

/*START*/
void		construct_stack(t_input *input, t_stack *stack);
void		read_and_exec(t_stack *stack, t_input *input);

/*COMMANDS*/
int			pb(t_stack *stack, int print);
int			pa(t_stack *stack, int print);
int			ra(t_stack *stack, int print);
int			rb(t_stack *stack, int print);
int			rr(t_stack *stack, int print);
int			rra(t_stack *stack, int print);
int			rrb(t_stack *stack, int print);
int			rrr(t_stack *stack, int print);
int			sa(t_stack *stack, int print);
int			sb(t_stack *stack, int print);
int			ss(t_stack *stack, int print);

/*END CHECKS*/
int			is_sorted(t_list *stack);
t_list		*pluck_first(t_list **lst);
t_list		*pluck_last(t_list **lst);
void		del(void *content);
void		b_crash(int err, t_stack *stack, t_input *input);

void		print_current_stacks(t_stack *stack);
void		print_output(char *msg, t_stack *stack);
#endif
