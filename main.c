/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 21:22:43 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	t_input	input;
	t_stack	*stack;
	t_parts	p;
	t_rot	best;
	int		i;

	i = 0;
	input.args = argv[1];
	input.arr = parse_numbers(&input);
	stack = init_input(&input);
	ft_lstiter(stack->a_top, print_content);
	printf("\n\n");
	find_parts(&p, &input);
	quick_sort(input.control, 0, input.nr_count - 1);
	is_sorted(stack->a_top, input.control[p.min]);
	push_l_to_b(stack, &input, &p);
	push_h_to_b(stack, &input, &p);
	sort_bps(stack, &input, &p);
	while (stack->b_top != NULL)
	{
		best = find_best_rotation(stack, &input, &p);
		execute_best(best, stack);
		pa(stack);
		print_current_stacks(stack);
	}
	finish_rotations(stack, &input);
	print_current_stacks(stack);


}

void	finish_rotations(t_stack *stack, t_input *input)
{
	int		i;
	int		a_n;
	t_rot	rot;
	t_list	*temp;

	i = 0;
	ft_bzero(&rot, sizeof(rot));
	a_n = ft_lstsize(stack->a_top);
	temp = stack->a_top;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content != input->control[0])
		{
			i++;
			temp = temp->next;
			continue ;
		}
		break ;
	}
	if (i > a_n - i)
		rot.rra = a_n - i;
	else
		rot.ra = i;
	execute_best(rot, stack);
}

void	execute_best(t_rot best, t_stack *stack)
{
	while (best.ra--)
		ra(stack);
	while (best.rb--)
		rb(stack);
	while (best.rr--)
		rr(stack);
	while (best.rra--)
		rra(stack);
	while (best.rrb--)
		rrb(stack);
	while (best.rrr--)
		rrr(stack);
}
//both up - 0
//both down - 1
//up-down - 2
//down-up - 3
t_list	*node_at_index(t_list *list, int a_index)
{
	while (a_index--)
		list = list->next;
	return (list);
}

int	find_a_spot(t_stack *stack)
{
	int		a_top;
	int		b_top;
	int		a_bot;
	int		a_index;
	t_list	*current;

	b_top = *(int *)stack->b_top->content;
	a_bot = *(int *)ft_lstlast(stack->a_top)->content;
	a_index = 0;
	while (42)

	{
		current = node_at_index(stack->a_top, a_index);
		a_top = *(int *)current->content;
		if (a_top < b_top)
			{
				a_index++;
				a_bot = a_top;
				continue ;
			}
		if (a_top > b_top)
		{
			if (a_bot > b_top)
			{
				a_index++;
				a_bot = a_top;
				continue ;
			}
		}
		return (a_index);
	}
}

void	get_rotations(t_stack *stack, int a_idx, int b_idx, t_rot *rot)
{

	ft_bzero(rot, sizeof(*rot) * 4);
	both_up(stack, a_idx, b_idx, rot);
	both_down(stack, a_idx, b_idx, rot);
	up_down(stack, a_idx, b_idx, rot);
	down_up(stack, a_idx, b_idx, rot);

}

t_rot	find_best_rotation(t_stack *stack, t_input *input, t_parts *p)
{
	int		a_index;
	int		b_index;
	t_rot	rot[4];
	t_rot	best;
	t_rot	current;
	int		i;
	int		b_size;

	b_index = 0;
	a_index = find_a_spot(stack);
	get_rotations(stack, a_index, b_index, rot);
	best = rot[0];
	b_size = ft_lstsize(stack->b_top);
	while (b_index < b_size)
	{
		i = 0;
		while (i < 4)
		{
			current = rot[i++];
			if (current.cost < best.cost)
				best = current;
		}
		// if (best.cost <= 1)
		// 	return (best);
		ft_putstr_fd("\n@", 1);
		ft_putnbr_fd(b_index, 1);
		ft_putstr_fd(" current best: ", 1);
		ft_putnbr_fd(best.cost, 1);
		b_index++;
		get_rotations(stack, a_index, b_index, rot);
	}
	return (best);
}

int	is_sorted(t_list *list, int min)
{
	int	current;

	if (*(int *)list->content != min)
		return (0);
	current = min;
	while (list && list->next != NULL)
	{
		if (*(int *)list->next->content > current)
			current = *(int *)list->next->content;
		else
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort_bps(t_stack *stack, t_input *input, t_parts *p)
{
	t_list	biggest;
	int		first;
	int		second;

	if (is_sorted(stack->a_top, input->control[p->min]))
		return ;
	first = *(int *)stack->a_top->content;
	second = *(int *)stack->a_top->next->content;
	if (first == input->control[p->max])
	{
		ra(stack);
		ft_putendl_fd("\n\nrotated A", 1);
		print_current_stacks(stack);
	}
	else if (second == input->control[p->max])
	{
		rra(stack);
		ft_putendl_fd("\n\nR-rotated A", 1);
		print_current_stacks(stack);
	}
	first = *(int *)stack->a_top->content;
	second = *(int *)stack->a_top->next->content;
	if (first < second)
		return ;
	sa(stack);
	ft_putendl_fd("\n\nswapped A", 1);
	print_current_stacks(stack);
}

void	push_h_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	while (ft_lstsize(stack->a_top) > 3)
	{
		int	a_int_top;

		a_int_top = *(int *)stack->a_top->content;
		if (is_breakpoint(a_int_top, p, input))
		{
			ra(stack);
			ft_putendl_fd("\n\nrotated A", 1);
			print_current_stacks(stack);
			continue ;
		}
		pb(stack);
		ft_putendl_fd("\n\npushed to B", 1);
		print_current_stacks(stack);
	}
}

void find_parts(t_parts *p, t_input *input)
{
	p->min = 0;
	p->low_mid = (input->nr_count) / 4;
	p->mid = input->nr_count / 2;
	p->high_mid = (input->nr_count) * 3 / 4;
	p->max = input->nr_count - 1;
}

int is_breakpoint(int content, t_parts *p, t_input *input)
{
	if (content == input->control[p->min])
		return (1);
	if (content == input->control[p->mid])
		return (1);
	if (content == input->control[p->max])
		return (1);
	return (0);
}

void push_l_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	int	a_top_int;

	while (ft_lstsize(stack->a_top) > p->max - p->high_mid + 2)
	{
		a_top_int = *(int *)stack->a_top->content;
		if (is_breakpoint(a_top_int, p, input) || a_top_int > input->control[p->high_mid])
		{
			ra(stack);
			ft_putendl_fd("\n\nrotated A", 1);
			print_current_stacks(stack);
			continue ;
		}
		pb(stack);
		ft_putendl_fd("\n\npushed to B", 1);
		print_current_stacks(stack);
		if (a_top_int < input->control[p->low_mid])
		{

			sb(stack);
			ft_putendl_fd("\n\nswapped B", 1);
			print_current_stacks(stack);
		}

	}
}

void	print_current_stacks(t_stack *stack)
{
	ft_putstr_fd("A_:", 1);
	ft_lstiter(stack->a_top, print_content);
	ft_putstr_fd("\nB_:", 1);
	ft_lstiter(stack->b_top, print_content);
}

void	print_content(void *content)
{
	ft_putnbr_fd(*(int *)content, 1);
	ft_putchar_fd(' ', 1);
}

t_stack *init_input(t_input *input)
{
	t_stack *stack;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a_top = NULL;
	if (input->arr && input->nr_count > 0)
		while (++i < input->nr_count)
			ft_lstadd_back(&stack->a_top, ft_lstnew(&input->arr[i]));
	return (stack);


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
	int			*control;
	char		*n_str;

	n_str = input->args;
	i = 0;
	input->nr_count = count_nrs(input->args);
	arr = malloc(input->nr_count * sizeof(int));
	control = malloc(input->nr_count * sizeof(int));
	if (!arr || !control)
		return (NULL);
	while (input->nr_count > i)
	{
		if (ft_isdigit(*n_str))
		{
			arr[i] = ft_atoi(n_str);
			control[i] = ft_atoi(n_str);
			n_str += count_digits(arr[i]) + 1;
		}
		i++;
	}
	input->control = control;
	return (arr);
}

void quick_sort(int *arr, int start, int end)
{
	int	p;

	if (start < end)
	{
		p = partition(arr, start, end);
		quick_sort(arr, start, p - 1);
		quick_sort(arr, p + 1, end);
	}
}

int partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int temp;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	return (i + 1);
}
