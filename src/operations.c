/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:09:43 by dkros             #+#    #+#             */
/*   Updated: 2024/06/06 15:17:07 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_stack *stack_x)
{
	t_node	*last;

	if (stack_x->top == NULL || stack_x->top->next == NULL)
		return ;
	last = stack_x->top;
	while (last->next != NULL)
		last = last->next;
	last->next = stack_x->top;
	stack_x->top->prev = last;
	stack_x->top = stack_x->top->next;
	stack_x->top->prev = NULL;
	last->next->next = NULL;
	ft_printf("r%c\n", stack_x->id);
	return ;
}

void	rotate_reverse(t_stack *stack_x)
{
	t_node	*last;

	if (stack_x->top == NULL || stack_x->top->next == NULL)
		return ;
	last = stack_x->top;
	while (last->next != NULL)
		last = last->next;
	last->next = stack_x->top;
	stack_x->top->prev = last;
	stack_x->top = last;
	stack_x->top->prev->next = NULL;
	stack_x->top->prev = NULL;
	ft_printf("rr%c\n", stack_x->id);
	return ;
}

long	ft_pop(t_stack *stack)
{
	long	data;
	t_node	*temp;

	if (stack->top == NULL)
	{
		ft_printf("Stack underflow\n");
		exit(1);
	}
	temp = stack->top;
	data = temp->data;
	stack->top = stack->top->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	free(temp);
	return (data);
}

void	push(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*new_node;

	if (stack_b == NULL || stack_a == NULL)
		return ;
	if (stack_b->top == NULL)
		return ;
	new_node = create_node(ft_pop(stack_b));
	if (new_node == NULL)
		return ;
	stack_a->size++;
	stack_b->size--;
	if (!stack_a->top)
		stack_a->top = new_node;
	else
	{
		new_node->next = stack_a->top;
		stack_a->top->prev = new_node;
		stack_a->top = new_node;
	}
	ft_printf("p%c\n", stack_a->id);
	return ;
}

void	swap(t_stack *stack_x)
{
	int	temp;

	if (!stack_x->top || !stack_x->top->next)
		return ;
	temp = stack_x->top->data;
	stack_x->top->data = stack_x->top->next->data;
	stack_x->top->next->data = temp;
	ft_printf("s%c\n", stack_x->id);
	return ;
}
