/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:25:06 by dkros             #+#    #+#             */
/*   Updated: 2024/06/06 18:02:43 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_push(t_stack *a, t_stack *b, int *highest)
{
	if (!is_empty(b) && a->top->data > b->top->data
		&& a->top->data < ft_bottom(b))
	{
		*highest = a->top->data;
		push(a, b);
		return (1);
	}
	return (0);
}

int	ft_bottom(t_stack *stack_x)
{
	t_node	*temp;

	temp = stack_x->top;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp->data);
}

void	ft_sort_three(t_stack *x)
{
	if (is_sorted(x) || x->size > 3)
		return ;
	if (x->top->data < ft_bottom(x) && ft_bottom(x) < x->top->next->data)
	{
		rotate_reverse(x);
		swap(x);
	}
	else if (x->top->next->data < ft_bottom(x) && ft_bottom(x) > x->top->data)
		swap(x);
	else if (x->top->next->data > x->top->data && ft_bottom(x) < x->top->data)
		rotate_reverse(x);
	else if (ft_bottom(x) < x->top->data && x->top->next->data < x->top->data
		&& x->top->next->data < ft_bottom(x))
		rotate_stack(x);
	else if (ft_bottom(x) < x->top->data && x->top->next->data < x->top->data)
	{
		rotate_stack(x);
		swap(x);
	}
	return ;
}

void	ft_sort_two(t_stack *x)
{
	if (x->size == 2)
	{
		if (x->top->data > x->top->next->data)
			swap(x);
	}
	return ;
}

int	is_sorted(t_stack *stack_x)
{
	t_node	*current;

	current = stack_x->top;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
