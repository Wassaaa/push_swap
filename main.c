/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:54:33 by aklein            #+#    #+#             */
/*   Updated: 2024/01/31 22:09:18 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int *parse_numbers(t_input *input);
void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
t_stack *init_input(t_input *input);
void print_content(void *content);
void find_parts(t_parts *parts, t_input *input);

int main(int argc, char **argv)
{
	t_input input;
	t_stack *a_stack;
	t_parts parts;
	int		i;

	i = 0;
	// printf("%d\n", argc);
	// printf("%s\n", argv[1]);

	input.args = argv[1];
	input.arr = parse_numbers(&input);
	a_stack = init_input(&input);
	ft_lstiter(a_stack->top, print_content);
	quick_sort(input.arr, 0, input.nr_count - 1);
	find_parts(&parts, &input);

	// while (i < input.nr_count)
	// 	printf("%d\n", input.arr[i++]);
	// i = 0;
	// while (i < input.nr_count)
	// 	printf("%d\n", input.arr[i++]);
	// printf("%d\n\n", ft_lstsize(a_stack->top));
}

void find_parts(t_parts *parts, t_input *input)
{
	parts->min = 0;
	parts->low_mid = (input->nr_count) / 4;
	parts->mid = input->nr_count / 2;
	parts->high_mid = (input->nr_count) * 3 / 4;
	parts->max = input->nr_count - 1;
}

void print_content(void *content)
{
	printf("%d ", *(int *)content);
}

t_stack *init_input(t_input *input)
{
	t_stack *stack;
	int		i;

	i = -1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	if (input->arr && input->nr_count > 0)
		while (++i < input->nr_count)
			ft_lstadd_back(&stack->top, ft_lstnew(&input->arr[i]));
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
