/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 02:51:57 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int *parse_numbers(t_input *input);
void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
t_stack *init_input(t_input *input);
void print_content(void *content);
void find_parts(t_parts *p, t_input *input);

int main(int argc, char **argv)
{
	t_input input;
	t_stack *stack;
	t_parts p;
	int		i;

	i = 0;
	// printf("%d\n", argc);
	// printf("%s\n", argv[1]);

	input.args = argv[1];
	input.arr = parse_numbers(&input);
	stack = init_input(&input);
	ft_lstiter(stack->a_top, print_content);
	printf("\n\n");
	find_parts(&p, &input);
	quick_sort(input.control, 0, input.nr_count - 1);
	push_to_b(stack, &input, &p);

	// while (i < input.nr_count)
	// 	printf("%d\n", input.arr[i++]);
	// i = 0;
	// while (i < input.nr_count)
	// 	printf("%d\n", input.arr[i++]);
	// printf("%d\n\n", ft_lstsize(a_stack->top));
}

// void find_parts(t_parts *p, t_input *input)
// {
// 	p->min = input->arr[0];
// 	p->low_mid = input->arr[(input->nr_count) / 4];
// 	p->mid = input->arr[input->nr_count / 2];
// 	p->high_mid = input->arr[(input->nr_count) * 3 / 4];
// 	p->max = input->arr[input->nr_count - 1];
// }
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

void push_to_b(t_stack *stack, t_input *input, t_parts *p)
{
	int	a_top_int;

	while (ft_lstsize(stack->a_top) > p->max - p->high_mid + 2)
	{
		a_top_int = *(int *)stack->a_top->content;
		if (is_breakpoint(a_top_int, p, input) || a_top_int > input->control[p->high_mid])
		{
			ra(stack);
			ft_putstr_fd("\n\nA_:", 1);
			ft_lstiter(stack->a_top, print_content);
			ft_putstr_fd("\nB_:", 1);
			ft_lstiter(stack->b_top, print_content);
			continue ;
		}
		pb(stack);
		if (a_top_int < input->control[p->low_mid])
			sb(stack);
		ft_putstr_fd("\n\nA_:", 1);
		ft_lstiter(stack->a_top, print_content);
		ft_putstr_fd("\nB_:", 1);
		ft_lstiter(stack->b_top, print_content);
	}
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
