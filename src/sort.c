/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:47:03 by dkros             #+#    #+#             */
/*   Updated: 2024/06/06 17:31:21 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../push_swap.h"
#include <stdlib.h>
#include <string.h>

void	radix_sort(t_stack *a, t_stack *b, int max_bits)
{
	int	j;
	int	i;
	int	size;

	j = 0;
	size = a->size;
	while (!is_sorted(a) && j < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->data >> j) & 1) == 1)
				rotate_stack(a);
			else
				push(a, b);
			i++;
		}
		while (!is_empty(b))
			push(b, a);
		j++;
	}
	return ;
}

int	*count_bits(t_stack *stack)
{
	int		i;
	int		*bit_counts;
	t_node	*current;

	bit_counts = (int *)calloc(64, sizeof(int));
	if (bit_counts == NULL)
		return (NULL);
	current = stack->top;
	while (current != NULL)
	{
		i = 0;
		while (i < 64)
		{
			if (current->data & (1 << i))
				bit_counts[i]++;
			i++;
		}
		current = current->next;
	}
	return (bit_counts);
}

long	find_min(t_stack *a)
{
	long	min;
	t_node	*current;

	if (a == NULL || a->size == 0)
		return (INT_MAX);
	min = a->top->data;
	current = a->top;
	while (current != NULL)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

long	find_second_min(t_stack *a)
{
	long	min;
	long	second_min;
	t_node	*current;

	second_min = INT_MAX;
	if (a == NULL || a->size <= 1)
		return (INT_MAX);
	min = find_min(a);
	current = a->top;
	while (current != NULL)
	{
		if (current->data < second_min && current->data != min)
			second_min = current->data;
		current = current->next;
	}
	return (second_min);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	long	min;
	long	second_min;

	min = find_min(a);
	second_min = find_second_min(a);
	if (is_sorted(a))
		return ;
	while (a->size > 3)
	{
		if (a->top->data == min || a->top->data == second_min)
			push(a, b);
		else
			rotate_stack(a);
	}
	ft_sort_three(a);
	while (b->size > 0)
		push(b, a);
	if (a->top->data > a->top->next->data)
		swap(a);
	return ;
}
