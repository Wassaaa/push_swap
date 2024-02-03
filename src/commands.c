/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:10:54 by aklein            #+#    #+#             */
/*   Updated: 2024/02/03 19:59:46 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*pluck_first(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	return (temp);
}

t_list	*pluck_last(t_list **lst)
{
	t_list	*temp;
	t_list	*new_last;

	temp = *lst;
	if (lst == NULL || *lst == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			new_last = temp;
		temp = temp->next;
	}
	new_last->next = NULL;
	return (temp);
}

void	ra(t_stack *stack)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
		return ;
	next = stack->a_top->next;
	plucked = pluck_first(&stack->a_top);
	stack->a_top = next;
	ft_lstadd_back(&stack->a_top, plucked);
}

void	rra(t_stack *stack)
{
	t_list	*plucked;

	if (stack == NULL || stack->a_top == NULL || stack->a_top->next == NULL)
		return ;
	plucked = pluck_last(&stack->a_top);
	ft_lstadd_front(&stack->a_top, plucked);
}

void	rb(t_stack *stack)
{
	t_list	*plucked;
	t_list	*next;

	if (stack == NULL || stack->b_top == NULL || stack->b_top->next == NULL)
		return ;
	next = stack->b_top->next;
	plucked = pluck_first(&stack->b_top);
	stack->b_top = next;
	ft_lstadd_back(&stack->b_top, plucked);
}

void	pb(t_stack *stack)
{
	t_list	*plucked;
	t_list	*next;

	next = stack->a_top->next;
	plucked = pluck_first(&stack->a_top);
	stack->a_top = next;
	ft_lstadd_front(&stack->b_top, plucked);
	stack->b_top = plucked;
}

void	pa(t_stack *stack)
{
	t_list	*plucked;
	t_list	*next;

	next = stack->b_top->next;
	plucked = pluck_first(&stack->b_top);
	stack->b_top = next;
	ft_lstadd_front(&stack->a_top, plucked);
	stack->a_top = plucked;
}

void	sb(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->b_top == NULL)
		return ;
	if (stack->b_top->next == NULL)
		return ;
	first = pluck_first(&stack->b_top);
	second = pluck_first(&stack->b_top);
	ft_lstadd_front(&stack->b_top, first);
	ft_lstadd_front(&stack->b_top, second);
}

void	sa(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack == NULL || stack->a_top == NULL)
		return ;
	if (stack->a_top->next == NULL)
		return ;
	first = pluck_first(&stack->a_top);
	second = pluck_first(&stack->a_top);
	ft_lstadd_front(&stack->a_top, first);
	ft_lstadd_front(&stack->a_top, second);
}